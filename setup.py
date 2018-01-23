from distutils.core import setup, Extension

phi1612_hash_module = Extension('phi1612_hash',
                               sources = ['phi1612module.c',
                                          'phi1612.c',
										  'sph/aes_helper.c',
										  'sph/skein.c',
										  'sph/jh.c',
                                                                                  'sph/cubehash.c',
                                                                                  'sph/fugue.c',
                                                                                  'sph/gost.c',
										  'sph/echo.c'],
                               include_dirs=['.', './sph'])

setup (name = 'phi1612_hash',
       version = '1.0',
       description = 'Bindings for phi1612 proof of work used by BHCoin',
       ext_modules = [phi1612_hash_module])
