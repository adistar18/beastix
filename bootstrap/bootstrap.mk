bootstrap-binutils:
	cd ${SRC_ROOT}/bootstrap/binutils; ${SRC_ROOT}/world/binutils/configure ${BOOTSTRAP_CONFIG}
	make -C ${SRC_ROOT}/bootstrap/binutils all
	make -C ${SRC_ROOT}/bootstrap/binutils install-gas install-ld install-binutils

bootstrap-gcc: 
	cd ${SRC_ROOT}/bootstrap/gcc; ${SRC_ROOT}/world/gcc/configure ${BOOTSTRAP_CONFIG} --build=x86_64-unknown-linux-musl --enable-languages=c --with-newlib --disable-multilib \
                                                                                          --disable-libssp --disable-libquadmath --disable-threads --disable-decimal-float --disable-shared \
                                                                                          --disable-libmudflap --disable-libgomp
	make -C ${SRC_ROOT}/bootstrap/gcc all-gcc install-gcc
	make -C ${SRC_ROOT}/bootstrap/gcc all-target-libgcc install-gcc install-target-libgcc
	cd ${BOOTSTRAP_TOOLS}/bin; ln -s x86_64-unknown-linux-musl-gcc x86_64-unknown-linux-musl-cc

bootstrap-musl: bootstrap-gcc bootstrap-binutils
	export PATH=${BOOTSTRAP_PATH}; export CC=${BOOTSTRAP_CC}; cd ${SRC_DIR}/world/musl; ./configure ${BOOTSTRAP_CONFIG} --syslibdir=${BOOTSTRAP_TOOLS}/lib --host="x86_64-unknown-linux-musl" \
	                                                                                                                    --disable-gcc-wrapper --disable-shared --enable-static
	export PATH=${BOOTSTRAP_PATH}; export CC=${BOOTSTRAP_CC}; make -C ${SRC_DIR}/world/musl install

bootstrap-syslinux:
	@echo syslinux not yet integrated

bootstrap: bootstrap-musl bootstrap-binutils bootstrap-gcc bootstrap-syslinux
