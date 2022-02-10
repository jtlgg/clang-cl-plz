This is a [please](https://please.build/) example using clang (tested on macos with clang-13 from [pkgsrc](https://pkgsrc.joyent.com/install-on-osx/)) to compile native binaries for windows/linux/mac, using the native libraries/headers. 

To use:
- replace hardcoded paths in `./mkplzconfig.sh`, and run it to generate platform config files.
- build for platforms by workspace name: `///linux:all ///windows:all ///macos:all`:
```
$ plz build ///{windows,linux,macos}:test_executable
Build finished; total time 1.85s, incrementality 50.0%. Outputs:
///windows//:test_executable:
  plz-out/bin/windows/test_executable.exe
///linux//:test_executable:
  plz-out/bin/linux/test_executable
///macos//:test_executable:
  plz-out/bin/macos/test_executable
```

