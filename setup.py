from distutils.core import setup, Extension
setup(
    name="pycrocksdb",
    version="1.0",
    ext_modules=[Extension("pycrocksdb", ["src/pycrocksdbobject.c"])],
    extra_compile_args=["-I/rocksdb/"]
)
