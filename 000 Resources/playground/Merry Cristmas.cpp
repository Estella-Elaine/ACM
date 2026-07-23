#include <iostream>
#include <string>

// 简单静态彩色圣诞树（ANSI 颜色），不依赖线程或平台特殊头文件
int main() {
    const int height = 12; // 树高，可调整
    const std::string CSI = "\x1b[";
    const std::string RESET = CSI + "0m";
    const std::string GREEN = CSI + "32m";
    const std::string GREEN_BRIGHT = CSI + "92m";

    // 一些彩灯颜色
    const std::string red   = CSI + "31m";
    const std::string yellow= CSI + "33m";
    const std::string blue  = CSI + "34m";
    const std::string mag   = CSI + "35m";
    const std::string cyan  = CSI + "36m";
    const std::string white = CSI + "97m";

    const int width = 2 * height + 1;
    const int center = width / 2;

    // 树冠
    for (int r = 0; r < height; ++r) {
        int stars = 2 * r + 1;
        int left = center - r;
        // 左空格
        for (int i = 0; i < left; ++i) std::cout << ' ';
        for (int i = 0; i < stars; ++i) {
            // 用简单规则放置彩灯：按位置周期显示彩色 'o'
            if ((r + i) % 7 == 0) std::cout << red << 'o' << RESET;
            else if ((r + i) % 7 == 1) std::cout << yellow << 'o' << RESET;
            else if ((r + i) % 7 == 2) std::cout << blue << 'o' << RESET;
            else if ((r + i) % 7 == 3) std::cout << mag << 'o' << RESET;
            else if ((r + i) % 7 == 4) std::cout << cyan << 'o' << RESET;
            else if ((r + i) % 7 == 5) std::cout << white << 'o' << RESET;
            else {
                // 叶子：交替使用深/亮绿色
                if (r % 2 == 0) std::cout << GREEN << '*' << RESET;
                else std::cout << GREEN_BRIGHT << '*' << RESET;
            }
        }
        std::cout << '\n';
    }

    // 树干
    int trunkWidth = height / 4;
    if (trunkWidth < 1) trunkWidth = 1;
    if (trunkWidth % 2 == 0) ++trunkWidth;
    int trunkHeight = std::max(2, height / 5);
    int trunkLeft = center - trunkWidth / 2;
    for (int t = 0; t < trunkHeight; ++t) {
        for (int i = 0; i < trunkLeft; ++i) std::cout << ' ';
        std::cout << CSI + "33m"; // 棕/黄
        for (int i = 0; i < trunkWidth; ++i) std::cout << '#';
        std::cout << RESET << '\n';
    }

    // 底部彩色 Merry Christmas!
    const std::string message = "Merry Christmas!";
    int msgLeft = center - (int)message.size() / 2;
    std::cout << '\n';
    for (int i = 0; i < msgLeft; ++i) std::cout << ' ';
    // 给每个字符轮换颜色
    const std::string cols[] = {red, yellow, blue, mag, cyan, white, GREEN_BRIGHT};
    for (size_t i = 0; i < message.size(); ++i) {
        char ch = message[i];
        if (ch == ' ') { std::cout << ' '; continue; }
        std::cout << cols[i % (sizeof(cols)/sizeof(cols[0]))] << ch << RESET;
    }
    std::cout << '\n';

    return 0;
}