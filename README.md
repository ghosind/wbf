# wbf

![Travis CI](https://travis-ci.org/ghosind/wbf.svg?branch=master)

A simple BrainFuck language interpreter.

## Getting Start

### Dependencies

Wbf require readline library, you should install libreadline before build it.

For Mac OS: 

```sh
$ brew install readline
```

For CentOS / Fedora:

```sh
$ yum install readline-devel
```

For Debian / Ubuntu:

```sh
$ apt-get install libreadline-dev
```

### Build

Just run `make`, and it will generate binary file `wbf` to the `dist` directory.

### Usage

```
$ wbf [file_name]
```

## Contribution

1. Fork the Project.
2. Create your Branch. (`git checkout -b features/someFeatures`)
3. Commit your Changes. (`git commit -m 'Add some features'`)
4. Push to the Branch. (`git push origin features/someFeatures`)
5. Create a new Pull Request.

## License

Distributed under the GPLv3 License. See [LICENSE](./LICENSE) for more information.
