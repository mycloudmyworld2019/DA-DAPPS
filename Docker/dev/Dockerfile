FROM DA-DAPPSio/builder
ARG branch=master
ARG symbol=SYS

RUN git clone -b $branch https://github.com/DA-DAPPSio/DA-DAPPS.git --recursive \
    && cd DA-DAPPS && echo "$branch:$(git rev-parse HEAD)" > /etc/DA-DAPPSio-version \
    && cmake -H. -B"/opt/DA-DAPPSio" -GNinja -DCMAKE_BUILD_TYPE=Release -DWASM_ROOT=/opt/wasm -DCMAKE_CXX_COMPILER=clang++ \
       -DCMAKE_C_COMPILER=clang -DCMAKE_INSTALL_PREFIX=/opt/DA-DAPPSio -DBUILD_MONGO_DB_PLUGIN=true -DCORE_SYMBOL_NAME=$symbol \
    && cmake --build /opt/DA-DAPPSio --target install \
    && cp /DA-DAPPS/Docker/config.ini / && ln -s /opt/DA-DAPPSio/contracts /contracts && cp /DA-DAPPS/Docker/nodeosd.sh /opt/DA-DAPPSio/bin/nodeosd.sh && ln -s /DA-DAPPS/tutorials /tutorials

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get -y install openssl ca-certificates vim psmisc python3-pip && rm -rf /var/lib/apt/lists/*
RUN pip3 install numpy
ENV DA-DAPPSio_ROOT=/opt/DA-DAPPSio
RUN chmod +x /opt/DA-DAPPSio/bin/nodeosd.sh
ENV LD_LIBRARY_PATH /usr/local/lib
ENV PATH /opt/DA-DAPPSio/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
