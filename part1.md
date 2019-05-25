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

### 光年

とりあえず1光年の計算でもやってみるか。まずは光速の定義から。
えーと、サンプルに

```
mitama::quantity_t<si::area_t, int> area = width * height;
``` 

とあるのだし、こうすればよいかな。

```
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/area.hpp>
#include <cstdint>

int main()
{
    namespace si = mitama::systems::si;
    mitama::quantity_t<si::velocity_t, int64_t> speed_of_light = 299'792'458;
}
```

結果の値はintだとオーバーフローするので、`#include <cstdint>`して`int64_t`を使う。また、C++14から`299'792'458`と書けるようになったので、使っていく。

えっと

```
$ clang++ lightyear.cpp --include-directory mitama-dimensional/include/ -std=c++17
lightyear.cpp:11:28: error: no member named 'velocity_t' in namespace
      'mitama::systems::si'
    mitama::quantity_t<si::velocity_t, int64_t> speed_of_light = 299'792'458;
                       ~~~~^
lightyear.cpp:11:49: error: C++ requires a type specifier for all declarations
    mitama::quantity_t<si::velocity_t, int64_t> speed_of_light = 299'792'458;
                                                ^
2 errors generated.
```

んー？

…あ、ヘッダのインクルード忘れか。

```
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/velocity.hpp>
#include <cstdint>

int main()
{
    namespace si = mitama::systems::si;
    mitama::quantity_t<si::velocity_t, int64_t> speed_of_light = 299'792'458;
}
```

OK。ということで光秒・光分・光時・光日が計算できる。

```
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/velocity.hpp>
#include <dimensional/systems/nonsi/minute.hpp>
#include <dimensional/systems/nonsi/hour.hpp>
#include <dimensional/systems/nonsi/day.hpp>
#include <cstdint>
#include <iostream>

int main()
{
    namespace si = mitama::systems::si;
    namespace nonsi = mitama::systems::nonsi;
    mitama::quantity_t<si::velocity_t, int64_t> speed_of_light = 299'792'458;

    mitama::quantity_t<si::meter_t, int64_t> light_second = speed_of_light * (1 | si::seconds);
    std::cout << "light second:   " << light_second << std::endl;

    mitama::quantity_t<si::meter_t, int64_t> light_minute = speed_of_light * (1 | nonsi::minutes);
    std::cout << "light minute: " << light_minute << std::endl;

    mitama::quantity_t<si::meter_t, int64_t> light_hour = speed_of_light * (1 | nonsi::hours);
    std::cout << "light hour: " << light_hour << std::endl;

    mitama::quantity_t<si::meter_t, int64_t> light_day = speed_of_light * (1 | nonsi::days);
    std::cout << "light day: " << light_day << std::endl;
}
```

```
$ clang++ lightyear.cpp --include-directory mitama-dimensional/include/ -std=c++17
$ ./a.out
light second:   299792458 [m]
light minute: 17987547480 [m]
light hour: 1079252848800 [m]
light day: 25902068371200 [m]
```

計算ができる。

さて、光年である。Fizzbuzzの次に有名な、余りに関するアルゴリズムとして閏年判定があるが、この判定法は1年を 365 + 1/4 - 1/100 + 1/400 = 365.2425日として近似する方法である。

だが、1光年の定義は「光速度 × **1ユリウス年（365.25日）**」である。365.25は当然浮動小数点数(IEEE 754)で正確に表現できる値であるが、1光年 / 1メートルが 64bit浮動小数点数の精度範囲に収まるかどうかは甚だ不安である。（注：実は、9460730472580800 > 9007199254740991 なので、JavaScriptでいうsafe integerの範囲にギリギリ収まらない。）

ということで、先に1ユリウス年を秒で表して、それを光速度に掛け算することにしよう。

```
	...
	mitama::quantity_t<si::second_t, double> julian_year = (1 | nonsi::days) * 365.25;
    std::cout << "julian year: " << julian_year << std::endl;
    ...
```

```
$ clang++ lightyear.cpp --include-directory mitama-dimensional/include/ -std=c++17
lightyear.cpp:29:80: warning: implicit conversion from 'double' to 'typename
      std::decay_t<quantity_t<si_base_units<dimensional_t<units_t<time, ratio<1,
      1>, ratio<86400, 1> > > >, int> >::value_type' (aka 'int') changes value
      from 365.25 to 365 [-Wliteral-conversion]
  ...double> julian_year = (1 | nonsi::days) * 365.25;
                                             ~ ^~~~~~
1 warning generated.
```

おっと、これでは365.25が365に化けてしまう。`nonsi::days`の前に掛けるものを1.0にしなくては。

```
    ...
    mitama::quantity_t<si::second_t, double> julian_year = (1.0 | nonsi::days) * 365.25;
    std::cout << "julian year: " << julian_year << std::endl;
    ...
```

```
$ clang++ lightyear.cpp --include-directory mitama-dimensional/include/ -std=c++17
$ ./a.out
light second:   299792458 [m]
light minute: 17987547480 [m]
light hour: 1079252848800 [m]
light day: 25902068371200 [m]
julian year: 3.15576e+07 [s]
```

出力される。

あ、せっかくだし、IEEE 754であることを保証しておこう。

```
#include <limits>

    ...
    
    static_assert(std::numeric_limits<double>::is_iec559);
    static_assert(std::numeric_limits<double>::digits == 53);
```


次にこれをint64_tに移す必要がある。キャストってどうやるんだろう。`static_cast`でいいのかな。

```
    ...
    mitama::quantity_t<si::second_t, double> julian_year = (1.0 | nonsi::days) * 365.25;
    std::cout << "julian year: " << julian_year << std::endl;

    mitama::quantity_t<si::second_t, int64_t> julian_year_int = static_cast< mitama::quantity_t<si::second_t, int64_t>>(julian_year);
    std::cout << "julian year: " << julian_year_int << std::endl;
    ...
```

`static_cast`でいいっぽい。なんかこの話をしたらunderlying castがどうこうと言われたが、C++が分からないためよく分からない。後で調べとこう。

とりあえず、これで光年が計算できる。

```
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/velocity.hpp>
#include <dimensional/systems/nonsi/minute.hpp>
#include <dimensional/systems/nonsi/hour.hpp>
#include <dimensional/systems/nonsi/day.hpp>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
    namespace si = mitama::systems::si;
    namespace nonsi = mitama::systems::nonsi;
    mitama::quantity_t<si::velocity_t, int64_t> speed_of_light = 299'792'458;

    mitama::quantity_t<si::meter_t, int64_t> light_second = speed_of_light * (1 | si::seconds);
    std::cout << "light second:   " << light_second << std::endl;

    mitama::quantity_t<si::meter_t, int64_t> light_minute = speed_of_light * (1 | nonsi::minutes);
    std::cout << "light minute: " << light_minute << std::endl;

    mitama::quantity_t<si::meter_t, int64_t> light_hour = speed_of_light * (1 | nonsi::hours);
    std::cout << "light hour: " << light_hour << std::endl;

    mitama::quantity_t<si::meter_t, int64_t> light_day = speed_of_light * (1 | nonsi::days);
    std::cout << "light day: " << light_day << std::endl;

    static_assert(std::numeric_limits<double>::is_iec559);
    static_assert(std::numeric_limits<double>::digits == 53);

    mitama::quantity_t<si::second_t, double> julian_year = (1.0 | nonsi::days) * 365.25;
    std::cout << "julian year: " << julian_year << std::endl;

    mitama::quantity_t<si::second_t, int64_t> julian_year_int = static_cast< mitama::quantity_t<si::second_t, int64_t>>(julian_year);
    std::cout << "julian year: " << julian_year_int << std::endl;

    mitama::quantity_t<si::meter_t, int64_t> light_year = speed_of_light * julian_year_int;
    std::cout << "light year: " << light_year << std::endl;
}
```

```
$ clang++ lightyear.cpp --include-directory mitama-dimensional/include/ -std=c++17
$ ./a.out
light second:   299792458 [m]
light minute: 17987547480 [m]
light hour: 1079252848800 [m]
light day: 25902068371200 [m]
julian year: 3.15576e+07 [s]
julian year: 31557600 [s]
light year: 9460730472580800 [m]
```

いなむのみたま「`cstdint`をインクルードしてるなら`int64_t`は`std::`付けたほうを使ったほうがよいです」  
私「ほんまや」

さらに、光速度は既にライブラリで定義されているので、そっちを使おう。

```
#include <dimensional/quantity.hpp>
#include <dimensional/arithmetic.hpp>
#include <dimensional/systems/si/all.hpp>
#include <dimensional/systems/si/derived_units/velocity.hpp>
#include <dimensional/systems/si/constants/constants.hpp>
#include <dimensional/systems/nonsi/minute.hpp>
#include <dimensional/systems/nonsi/hour.hpp>
#include <dimensional/systems/nonsi/day.hpp>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <limits>

int main()
{
    namespace si = mitama::systems::si;
    namespace nonsi = mitama::systems::nonsi;

    mitama::quantity_t<si::velocity_t, std::int64_t>
        speed_of_light = mitama::systems::si::constants::c<std::int64_t>;

    mitama::quantity_t<si::meter_t, std::int64_t> light_second = speed_of_light * (1 | si::seconds);
    std::cout << "light second:   " << light_second << std::endl;

    mitama::quantity_t<si::meter_t, std::int64_t> light_minute = speed_of_light * (1 | nonsi::minutes);
    std::cout << "light minute: " << light_minute << std::endl;

    mitama::quantity_t<si::meter_t, std::int64_t> light_hour = speed_of_light * (1 | nonsi::hours);
    std::cout << "light hour: " << light_hour << std::endl;

    mitama::quantity_t<si::meter_t, std::int64_t> light_day = speed_of_light * (1 | nonsi::days);
    std::cout << "light day: " << light_day << std::endl;

    static_assert(std::numeric_limits<double>::is_iec559);
    static_assert(std::numeric_limits<double>::digits == 53);

    mitama::quantity_t<si::second_t, double> julian_year = (1.0 | nonsi::days) * 365.25;
    std::cout << "julian year: " << julian_year << std::endl;

    mitama::quantity_t<si::second_t, std::int64_t> julian_year_int = static_cast< mitama::quantity_t<si::second_t, std::int64_t>>(julian_year);
    std::cout << "julian year: " << julian_year_int << std::endl;

    mitama::quantity_t<si::meter_t, std::int64_t> light_year = speed_of_light * julian_year_int;
    std::cout << "light year: " << light_year << std::endl;
}
```

これでコンパイル。

```
$ clang++ lightyear.cpp --include-directory mitama-dimensional/include/ -std=c++17
In file included from lightyear.cpp:5:
mitama-dimensional/include/dimensional/systems/si/constants/constants.hpp:1:10: fatal error: 
      'dimensional/all.hpp' file not found
#include <dimensional/all.hpp>
         ^~~~~~~~~~~~~~~~~~~~~
1 error generated.
```

…あれ？

いなむのみたま「あっ、これはマズい」

ということで手動で`#include <dimensional/systems/si/all.hpp>`へと修正して、

```
$ clang++ lightyear.cpp --include-directory mitama-dimensional/include/ -std=c++17
$ ./a.out
light second:   299792458 [m]
light minute: 17987547480 [m]
light hour: 1079252848800 [m]
light day: 25902068371200 [m]
julian year: 3.15576e+07 [s]
julian year: 31557600 [s]
light year: 9460730472580800 [m]
```

と無事出力できた。
