#!/bin/sh
cd /opt/DA-DAPPSio/bin

if [ ! -d "/opt/DA-DAPPSio/bin/data-dir" ]; then
    mkdir /opt/DA-DAPPSio/bin/data-dir
fi

if [ -f '/opt/DA-DAPPSio/bin/data-dir/config.ini' ]; then
    echo
  else
    cp /config.ini /opt/DA-DAPPSio/bin/data-dir
fi

if [ -d '/opt/DA-DAPPSio/bin/data-dir/contracts' ]; then
    echo
  else
    cp -r /contracts /opt/DA-DAPPSio/bin/data-dir
fi

while :; do
    case $1 in
        --config-dir=?*)
            CONFIG_DIR=${1#*=}
            ;;
        *)
            break
    esac
    shift
done

if [ ! "$CONFIG_DIR" ]; then
    CONFIG_DIR="--config-dir=/opt/DA-DAPPSio/bin/data-dir"
else
    CONFIG_DIR=""
fi

exec /opt/DA-DAPPSio/bin/nodeos $CONFIG_DIR "$@"
