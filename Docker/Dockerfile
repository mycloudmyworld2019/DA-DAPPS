FROM DA-DAPPSio/builder as builder
ARG branch=master
ARG symbol=SYS

RUN apt-get update -y && apt-get install -y libcurl4-openssl-dev libusb-1.0-0-dev
RUN git clone -b $branch https://github.com/DA-DAPPSio/DA-DAPPS.git --recursive \
    && cd DA-DAPPS && echo "$branch:$(git rev-parse HEAD)" > /etc/DA-DAPPSio-version \
    && cmake -H. -B"/tmp/build" -GNinja -DCMAKE_BUILD_TYPE=Release -DWASM_ROOT=/opt/wasm -DCMAKE_CXX_COMPILER=clang++ \
       -DCMAKE_C_COMPILER=clang -DCMAKE_INSTALL_PREFIX=/tmp/build -DBUILD_MONGO_DB_PLUGIN=true -DCORE_SYMBOL_NAME=$symbol \
    && cmake --build /tmp/build --target install


FROM ubuntu:18.04

RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get -y install openssl ca-certificates && rm -rf /var/lib/apt/lists/*
COPY --from=builder /usr/local/lib/* /usr/local/lib/
COPY --from=builder /tmp/build/bin /opt/DA-DAPPSio/bin
COPY --from=builder /DA-DAPPS/Docker/config.ini /
COPY --from=builder /etc/DA-DAPPSio-version /etc
COPY --from=builder /DA-DAPPS/Docker/nodDA-DAPPSd.sh /opt/DA-DAPPSio/bin/nodDA-DAPPSd.sh
ENV DA-DAPPSio_ROOT=/opt/DA-DAPPSio
RUN chmod +x /opt/DA-DAPPSio/bin/nodDA-DAPPSd.sh
ENV LD_LIBRARY_PATH /usr/local/lib
ENV PATH /opt/DA-DAPPSio/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
