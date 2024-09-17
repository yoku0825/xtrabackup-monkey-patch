#
# keyring_kmip helpers
# Read KEYRING_TYPE[component|plugin] to decide which keyring type to setup
# If KEYRING_TYPE is not set, we assume component

. inc/common.sh

if [ -z ${KEYRING_TYPE+x} ]; then
  KEYRING_TYPE="component"
fi

instance_local_manifest=""
keyring_component_cnf=${TEST_VAR_ROOT}/component_keyring_kmip.cnf
keyring_args="--component-keyring-config=${keyring_component_cnf}"

# Check https://github.com/OpenKMIP/PyKMIP/wiki for how to use PyKMIP server
# Run https://github.com/OpenKMIP/PyKMIP/blob/master/bin/create_certificates.py
# to generate valid certificates.

KMIP_SERVER_ADDR="${KMIP_SERVER_ADDR:-127.0.0.1}"
KMIP_SERVER_PORT="${KMIP_SERVER_PORT:-5696}"
KMIP_CLIENT_CA="${KMIP_CLIENT_CA:-/etc/pykmip/client_certificate_jane_doe.pem}"
KMIP_CLIENT_KEY="${KMIP_CLIENT_KEY:-/etc/pykmip/client_key_jane_doe.pem}"
KMIP_SERVER_CA="${KMIP_SERVER_CA:-/etc/pykmip/root_certificate.pem}"
KMIP_OBJECT_GROUP="${KMIP_OBJECT_GROUP:-$(uuidgen)}"

function configure_keyring_file_component()
{
  if [ "$MYSQL_DEBUG_MODE" = "on" ]; then
    binary="mysqld-debug"
  else
    binary="mysqld"
  fi
  instance_local_manifest="${TEST_VAR_ROOT}/${binary}.my"
  cat <<EOF > "${MYSQLD_DATADIR}/${binary}.my"
{
    "components": "file://component_keyring_kmip"
}
EOF
  cat <<EOF > "${MYSQLD_DATADIR}/component_keyring_kmip.cnf"
{
  "server_addr": "${KMIP_SERVER_ADDR}",
  "server_port": "${KMIP_SERVER_PORT}",
  "client_ca": "${KMIP_CLIENT_CA}",
  "client_key": "${KMIP_CLIENT_KEY}",
  "server_ca": "${KMIP_SERVER_CA}",
  "object_group": "${KMIP_OBJECT_GROUP}"
}
EOF
cp "${MYSQLD_DATADIR}/${binary}.my" ${instance_local_manifest}
cp "${MYSQLD_DATADIR}/component_keyring_kmip.cnf" ${keyring_component_cnf}
}

function cleanup_keyring()
{
  echo "place holder" > /dev/null
}

function ping_kmip()
{
  echo test | socat - TCP4:${KMIP_SERVER_ADDR}:${KMIP_SERVER_PORT} || \
  return 1
}
