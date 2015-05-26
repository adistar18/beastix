PWD               != pwd
CFLAGS            :=
BOOTSTRAP_CFLAGS  :=
BOOTSTRAP_LDFLAGS :=
BOOTSTRAP_TOOLS   := ${PWD}/bootstrap/tools
BOOTSTRAP_CONFIG  := --target=x86_64-unknown-linux-musl --prefix=${BOOTSTRAP_TOOLS} --disable-install-libbfd --with-sysroot=${BOOTSTRAP_TOOLS}
BOOTSTRAP_PATH    := ${BOOTSTRAP_TOOLS}/bin:${BOOTSTRAP_TOOLS}/x86_64-unknown-linux-musl/bin:/bin:/usr/bin
BOOTSTRAP_CC      := x86_64-unknown-linux-musl-gcc
WORLD_CC          := x86_64-unknown-linux-musl-gcc
WORLD_CFLAGS      := -static -I${BOOTSTRAP_TOOLS}/usr/include/
WORLD_LDFLAGS     := -static
WORLD_BUILD       := ${PWD}/obj
SRC_ROOT          := ${PWD}
INSTALL_ROOT      := /

