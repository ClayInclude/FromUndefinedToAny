/**
 * index
 * @module
 * @author Clay
 * @date 2021/2/26
 */

"use strict";

// 单行注释

/*
 * 多行
 * 块级注释
 */

/**
 * 文档注释
 */

function doSomething()
{
    "use strict";
}

let sum = 1 + 2;
let diff = 1 - 2;

// noinspection ES6ConvertVarToLetConst,JSDuplicatedDeclaration
var message;
// noinspection ES6ConvertVarToLetConst,JSDuplicatedDeclaration
var message = "hi";

message = 100;

function test()
{
    // noinspection ES6ConvertVarToLetConst
    var localeMessage = "hi";
}

// error
// alert(localeMessage)

function test2()
{
    // 非严格模式下可以这样定义全局变量
    // noinspection JSUndeclaredVariable
    // globalMessage = "hi";
}

// test2();
// console.log(globalMessage);

// noinspection ES6ConvertVarToLetConst
var message1 = "hi", found = false, age = 29;

// string
console.log(typeof message1);
// boolean
console.log(typeof found);
// number
console.log(typeof age);
// undefined
console.log(typeof void 0);
// object
console.log(typeof null);
// function
console.log(typeof test);
// object
console.log(typeof {});
// object
console.log(typeof window);
// object
console.log(typeof /123/);
// object
console.log(typeof RegExp("123"));
// object
console.log(typeof new RegExp("123"));

let uVar1;
// 无论什么情况下都没有必要显式的将一个变量设置为 undefined
let uVar2 = undefined;

// noinspection EqualityComparisonWithCoercionJS
console.log(uVar1 == uVar2);
console.log(uVar1 === uVar2);

console.log(uVar1);
// error
// console.log(noDeclare);

// 严格模式下也允许对未声明变量做 typeof 运算s
// noinspection JSUnresolvedVariable
typeof noDeclare;

// 用 null 来表示空对象指针
let p = null;

// true
Boolean(true);
// false
Boolean(false);

// false ，其余为 true
Boolean("");

// false ，其余为 true
Boolean(0);
Boolean(NaN);

// false ，其余为 true
Boolean(null);

// false
Boolean(undefined);

let intNum = 55;

// 这种写法也支持
// let octalNum1 = 070;
let octalNum1 = 0o70;
// error
// let octalNum2 = 079;
let octalNum3 = 0O777;

let hexNum1 = 0xA;
let hexNum2 = 0X1f;

// 二进制字面量不知道哪个版本才支持的
let binNum1 = 0b01010101010;
let binNum2 = 0B10001011010;

let floatNum1 = 1.1;
let floatNum2 = 0.1;
// 不推荐
let floatNum3 = .1;

// 解析为1
let floatNum4 = 1.;
// 解析为整形
let floatNum5 = 10.0;
let floatNum6 = 3.125e7;
let floatNum7 = 3.333E33;

let floatNumA = 0.1;
let floatNumB = 0.2;

// false ， IEEE 754 通病
Boolean(floatNumA + floatNumB === 0.3);

let minNumber = Number.MIN_VALUE;
let maxNumber = Number.MAX_VALUE;

// false
Boolean(isFinite(minNumber + maxNumber));

// always false
// Boolean(NaN === NaN);
// true , isNaN 会先尝试将参数转为数字，即 isNaN(Number(param))
Boolean(isNaN(NaN));

// 1
Number(true);
// 0
Number(false);

// 1111 ，原样返回
Number(1111);

// 0
Number(null);

// NaN
Number(undefined);

// 支持二进制、八进制、十进制和十六进制的整数
Number("0b100");
Number("0o111");
Number("0x111");

// 支持十进制浮点数
Number("12.3e3");

// 0
Number("");

/**
 * 当参数是一个对象时
 * @param param {Object}
 */
function toNumber(param)
{
    let v = param.valueOf();

    if (!isNaN(v))
    {
        return v;
    }

    return Number(param.toString());
}

// parseInt 更多的是看其是否符合数值模式，尽可能地指定基数
// 1234
parseInt("1234blue");
// ES 3 认为是八进制， ES 5 认为是十进制
parseInt("070");

// parseFloat 只解析十进制
// 0
parseFloat("0xa");

// String.prototype.length 返回的字符数包括16位字符的数目
// 1
console.log("\u03a3".length);

// 字符串不可变
let lang = "Java";
lang += "Script";

// "true"
true.toString();
// "[object Object]"
({}).toString();
// "string"
"string".toString();
// "10"
(10).toString();
// "1010"
(10).toString(2);

// "null"
String(null);
// "undefined"
String(undefined);

// 不推荐省略圆括号
// let o = new Object();
let o = {};

// ES 中所有的数值都以 IEEE 754 64位格式存储，但位操作符先将64位的值转换为32位的整数，然后执行操作，最后将结果转回64位。

// 0
console.log(Infinity >> 0);
// 0
console.log(NaN >> 0);

/**
 * &&
 * 如果第一个操作数为 false 、 null 、 NaN 或 undefined ，则返回。
 * 否则返回第二个操作数
 */

/**
 * ||
 * 如果第一个为 true 或 对象、字符串，则返回。
 * 否则返回第二个操作数
 */
