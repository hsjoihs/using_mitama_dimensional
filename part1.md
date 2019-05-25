## やっていく

part0.mdでは無事にサンプルのコンパイルを通すことができた。ということで実際に使っていこう。

### submodule

ライブラリをコピーしてくるんじゃなくてgit submoduleで管理すればよい、ということを教わった。言われてみればそれはそう。

当然コマンドを覚えていないので [git-scm.com](https://git-scm.com/docs/git-submodule) を見に行く。

```
$ git submodule add https://github.com/LoliGothick/mitama-dimensional 
```

これでライブラリが `mitama-dimensional/include/` に入るので、include pathを修正する。

```
$ clang++ example1.cpp --include-directory mitama-dimensional/include/ -std=c++17
$
```

```
$ clang++ example3.cpp --include-directory mitama-dimensional/include/ -std=c++17
$
```

よし。