/**
 * example03
 * @author Clay
 * @date 2021/4/15
 */

#include <iostream>

// /**
//  * 注释对/* */ 不能嵌套
//  * @return
//  */
int main()
{
    std::cout << "/*";
    std::cout << "*/";
    // std::cout << /* "*/" */;
    std::cout << /* "*/" /* "/*" */;

    return 0;
}
