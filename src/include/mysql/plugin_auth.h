#ifndef MYSQL_PLUGIN_AUTH_INCLUDED
/* Copyright (c) 2010, 2024, Oracle and/or its affiliates.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License, version 2.0,
   as published by the Free Software Foundation.

   This program is designed to work with certain software (including
   but not limited to OpenSSL) that is licensed under separate terms,
   as designated in a particular file or component or in included license
   documentation.  The authors of MySQL hereby grant you an additional
   permission to link the program and your derivative works with the
   separately licensed software that they have either included with
   the program or referenced in the documentation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License, version 2.0, for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301  USA */

/**
  @file include/mysql/plugin_auth.h

  Authentication Plugin API.

  This file defines the API for server authentication plugins.
*/

#define MYSQL_PLUGIN_AUTH_INCLUDED

#include <mysql/plugin.h>

#define MYSQL_AUTHENTICATION_INTERFACE_VERSION 0x0201

#include "plugin_auth_common.h"

/* defines for MYSQL_SERVER_AUTH_INFO.password_used */

#define PASSWORD_USED_NO 0
#define PASSWORD_USED_YES 1
#define PASSWORD_USED_NO_MENTION 2

/* Authentication flags */

#define AUTH_FLAG_PRIVILEGED_USER_FOR_PASSWORD_CHANGE (1L << 0)
#define AUTH_FLAG_USES_INTERNAL_STORAGE (1L << 1)
#define AUTH_FLAG_REQUIRES_REGISTRATION (1L << 2)

struct auth_factor_desc {
  /**
    authentication string for 1st, 2nd and 3rd factor auth plugins
  */
  const char *auth_string;
  /**
    Length of authentication string for 1st, 2nd and 3rd factor auth plugins
  */
  unsigned long auth_string_length;
  /**
    Flag which tells if connecting user has performed registration or not.
  */
  unsigned int is_registration_required;
};

/**
  Provides server plugin access to authentication information
*/
struct MYSQL_SERVER_AUTH_INFO {
  /**
    User name as sent by the client and shown in USER().
    NULL if the client packet with the user name was not received yet.
  */
  char *user_name;

  /**
    Length of user_name
  */
  unsigned int user_name_length;

  /**
    Refers to multi_factor_auth_info based on which factor is being
    authenticated.
  */
  const char *auth_string;

  /**
    Length of auth_string
  */
  unsigned long auth_string_length;

  /**
    Matching account name as found in the mysql.user table.
    A plugin can override it with another name that will be
    used by MySQL for authorization, and shown in CURRENT_USER()
  */
  char authenticated_as[MYSQL_USERNAME_LENGTH + 1];

  /**
    The unique user name that was used by the plugin to authenticate.
    Plugins should put null-terminated UTF-8 here.
    Available through the @@EXTERNAL_USER variable.
  */
  char external_user[512];

  /**
    This only affects the "Authentication failed. Password used: %s"
    error message. has the following values :
    0 : %s will be NO.
    1 : %s will be YES.
    2 : there will be no %s.
    Set it as appropriate or ignore at will.
  */
  int password_used;

  /**
    Set to the name of the connected client host, if it can be resolved,
    or to its IP address otherwise.
  */
  const char *host_or_ip;

  /**
    Length of host_or_ip
  */
  unsigned int host_or_ip_length;

  /**
    Additional password
  */
  const char *additional_auth_string;

  /**
    Length of additional password
  */
  unsigned long additional_auth_string_length;

  /**
    Refers to which factor auth_string to consider during authentication.
  */
  unsigned int current_auth_factor;
  /**
    Refers to authentication details of 1st, 2nd or 3rd factor authentication
    method
  */
  auth_factor_desc *multi_factor_auth_info;
};

/**
  Function provided by the plugin which should perform authentication (using
  the vio functions if necessary) and return 0 if successful. The plugin can
  also fill the info.authenticated_as field if a different username should be
  used for authorization.
*/
typedef int (*authenticate_user_t)(MYSQL_PLUGIN_VIO *vio,
                                   MYSQL_SERVER_AUTH_INFO *info);

/**
  New plugin API to generate password digest out of authentication string.
  This function will first invoke a service to check for validity of the
  password based on the policies defined and then generate encrypted hash

  @param[out]   outbuf      A buffer provided by server which will hold the
                            authentication string generated by plugin.
  @param[in,out] outbuflen   Length of server provided buffer as IN param and
                            length of plugin generated string as OUT param.
  @param[in]    inbuf       auth string provided by user.
  @param[in]    inbuflen    auth string length.

  @retval  0 OK
  @retval  1 ERROR
*/
typedef int (*generate_authentication_string_t)(char *outbuf,
                                                unsigned int *outbuflen,
                                                const char *inbuf,
                                                unsigned int inbuflen);

/**
  Plugin API to validate password digest.

  @param[in]    inbuf     hash string to be validated.
  @param[in]    buflen    hash string length.

  @retval  0 OK
  @retval  1 ERROR
  */
typedef int (*validate_authentication_string_t)(char *const inbuf,
                                                unsigned int buflen);

/**
  Plugin API to convert scrambled password to binary form
  based on scramble type.

  @param[in]    password          The password hash containing the salt.
  @param[in]    password_len      The length of the password hash.
  @param[in,out] salt             Used as password hash based on the
                                  authentication plugin.
  @param[in,out] salt_len         The length of salt.

  @retval  0 OK
  @retval  1 ERROR
*/
typedef int (*set_salt_t)(const char *password, unsigned int password_len,
                          unsigned char *salt, unsigned char *salt_len);

/**
  Plugin API to compare a clear text password with a stored hash

  @arg hash              pointer to the hashed data
  @arg hash_length       length of the hashed data
  @arg cleartext         pointer to the clear text password
  @arg cleartext_length  length of the cleat text password
  @arg[out] is_error     non-zero in case of error extracting the salt
  @retval 0              the hash was created with that password
  @retval non-zero       the hash was created with a different password
*/
typedef int (*compare_password_with_hash_t)(const char *hash,
                                            unsigned long hash_length,
                                            const char *cleartext,
                                            unsigned long cleartext_length,
                                            int *is_error);

/**
  Server authentication plugin descriptor
*/
struct st_mysql_auth {
  int interface_version; /** version plugin uses */
  /**
    A plugin that a client must use for authentication with this server
    plugin. Can be NULL to mean "any plugin".
  */
  const char *client_auth_plugin;

  authenticate_user_t authenticate_user;
  generate_authentication_string_t generate_authentication_string;
  validate_authentication_string_t validate_authentication_string;
  set_salt_t set_salt;

  /**
    Authentication plugin capabilities
  */
  const unsigned long authentication_flags;

  compare_password_with_hash_t compare_password_with_hash;
};
#endif
