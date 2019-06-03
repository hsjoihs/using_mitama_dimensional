## やっていく

[part1.md](part1.md)では光年をメートルで表したときの厳密値を求めることができた。今度は、<s>微細構造定数の値を区間演算で求め、旧SIと新SIでの差を見ていこう。</s> 微細構造定数は単位系に依らないんだよなぁ。なにやろうか。

[cranberries/interval](https://github.com/LoliGothick/Cranberries)を使おうかとも思ったが、文字列から区間を作る機能がないため、[kv](http://verifiedby.me/kv/)を推奨された。

```
$ git submodule add https://github.com/mskashi/kv
```

boostが必要なので、

```
$ brew install boost
```

したあとに

```
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <iostream>
#include <kv/interval.hpp>
#include <kv/rdouble.hpp>

int main()
{
    using namespace mitama;
    namespace si = mitama::systems::si;
    using kv::interval;

    interval<double> a(1, 2);
    auto b = a | si::meters;
    std::cout << b + b << std::endl;
    std::cout << b - b << std::endl;
    std::cout << b * b << std::endl;
    std::cout << b / b << std::endl;
}
```

すれば

```
$ clang++ interval.cpp --include-directory mitama-dimensional/include/ --include-directory kv/  --include-directory /usr/local/opt/boost/include/ -std=c++17
$ ./a.out
[2,4] [m]
[-1,1] [m]
[1,4] [m^2]
[0.5,2] [dimensionless]
```

と無事上手くいく。なお、[kv](http://verifiedby.me/kv/)を推奨されてからコンパイルが上手く行くまでに1時間がかかってしまった。

いなむのみたま「C++はだいたい環境構築が一番むずかしい」

さて、微細構造定数をやっていきましょう。

