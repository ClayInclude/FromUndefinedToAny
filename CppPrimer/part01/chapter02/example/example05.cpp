/**
 * example05
 * @author Clay
 * @date 2021/4/20
 */

typedef double wages;
typedef wages base, *p;

using Int = int;

typedef char *pString;

pString const cStr = nullptr;
pString const * cPStr = nullptr;
pString *const cCPStr = nullptr;

auto v = cStr;

int i = 0;
int &r = i;

auto a = r;

int const ci = i;
int const &cr = ci;

auto b = ci;
auto c = cr;
auto d = &i;
auto e = &ci;

auto const f = ci;

auto &g = ci;
// auto &h = 42;
auto const &j = 42;

int func()
{
    return 0;
}

decltype(func()) sum= 0;
decltype(ci) x = 0;
decltype(cr) y = x;

decltype(r + 0) z1;

int *pi;
decltype(pi) z2;
decltype(*pi) z3 = i;
decltype(*pi + 1) z4;
decltype((*pi)) z5 = i;
decltype((*pi + 1)) z6;
