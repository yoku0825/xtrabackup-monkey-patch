.. _xbcloud_gcs:

===================================================
Using the xbcloud with Google Cloud Storage
===================================================

Creating a full backup with Google Cloud Storage
================================================================================

The support for Google Cloud Storage is implemented using the interoperability
mode. This mode was especially designed to interact with cloud services
compatible with Amazon S3.

.. seealso::

   Cloud Storage Interoperability
      https://cloud.google.com/storage/docs/interoperability

.. code-block:: bash
		
   $ xtrabackup --backup --stream=xbstream --extra-lsndir=/tmp --target-dir=/tmp | \
   xbcloud put --storage=google \
   --google-endpoint=`storage.googleapis.com` \
   --google-access-key='YOUR-ACCESSKEYID' \
   --google-secret-key='YOUR-SECRETACCESSKEY' \
   --google-bucket='mysql_backups'
   --parallel=10 \
   $(date -I)-full_backup

The following options are available when using Google Cloud Storage:

- --google-access-key = <ACCESS KEY ID>
- --google-secret-key = <SECRET ACCESS KEY>
- --google-bucket = <BUCKET NAME>
- --google-storage-class=name

.. note::

    The Google storage class name options are the following:
    
    * STANDARD
    * NEARLINE
    * COLDLINE
    * ARCHIVE
    
    .. seealso::
    
     `Google storage classes <https://cloud.google.com/storage/docs/storage-classes>`_
     `The default Google storage class depends on the storage class of the bucket <https://cloud.google.com/storage/docs/changing-default-storage-class>`_
    