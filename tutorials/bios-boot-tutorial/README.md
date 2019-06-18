# Bios Boot Tutorial

The `bios-boot-tutorial.py` script simulates the DA-DAPPSio bios boot sequence.

``Prerequisites``:

1. Python 3.x
2. CMake
3. git

``Steps``:

1. Install DA-DAPPSio binaries by following the steps outlined in below tutorial
[Install DA-DAPPSio binaries](https://github.com/DA-DAPPSio/DA-DAPPS#mac-os-x-brew-install)

2. Install DA-DAPPSio.cdt binaries by following the steps outlined in below tutorial
[Install DA-DAPPSio.cdt binaries](https://github.com/DA-DAPPSio/DA-DAPPSio.cdt#binary-releases)

3. Compile DA-DAPPSio.contracts

```bash
$ cd ~
$ git clone https://github.com/DA-DAPPSio/DA-DAPPSio.contracts.git
$ cd ./DA-DAPPSio.contracts/
$ ./build.sh
$ pwd

```

4. Make note of the directory where the contracts were compiled
The last command in the previous step printed on the bash console the contracts' directory, make note of it, we'll reference it from now on as `DA-DAPPSio_CONTRACTS_DIRECTORY`

5. Launch the `bios-boot-tutorial.py` script
Minimal command line to launch the script below, make sure you replace `DA-DAPPSio_CONTRACTS_DIRECTORY` with actual directory

```bash
$ cd ~
$ git clone https://github.com/DA-DAPPSio/DA-DAPPS.git
$ cd ./DA-DAPPS/tutorials/bios-boot-tutorial/
$ python3 bios-boot-tutorial.py --cleos="cleos --wallet-url http://127.0.0.1:6666 " --nodeos=nodeos --keosd=keosd --contracts-dir="/DA-DAPPSio_CONTRACTS_DIRECTORY/" -a

```

See [DA-DAPPSio Documentation Wiki: Tutorial - Bios Boot](https://github.com/DA-DAPPSio/DA-DAPPS/wiki/Tutorial-Bios-Boot-Sequence) for additional information.