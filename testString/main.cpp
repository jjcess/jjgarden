#include <iostream>
#include <string>

/*
    按住Ctrl，滚动鼠标滚轮，放大或缩小字体。

    Ctrl+Shift+C注释掉当前行或选中部分，Ctrl+Shift+X解除注释。

    Ctrl+T 和上一行交换位置。

    按住Ctrl再拖动选中内容，则将这部分内容在新位置复制一遍。

    按住Alt再方向键上下移动，则将这行上下移动。

    Tab：缩进当前行或选中块。

    Shift+Tab：减少缩进。

    写完关键词（如：if，for，while）后，按Ctrl+J自动补全格式。（格式和关键词可以自己去编辑器里设置）

    Ctrl+Z：撤销。

    Ctrl+Shift+Z：反悔撤销。

    Ctrl+C：复制。

    Ctrl+V：粘贴。

    Ctrl+X：剪切。

    Ctrl+A：全选。

    2.编译与运行部分：
    Ctrl + F9：编译
    Ctrl + F10：运行上次成功编译后的程序
    Ctrl +　Shift + F9:编译当前文件（而不是当前打开的工程项目）
    F9：编译并运行当前代码（如果编译错误会提示错误而不会运行）
    F8：debug
    F10:全屏
    Ctrl + C：终止正在运行的程序
    Ctrl + Z：终止输入

    3.调试部分：

    F5：在当前光标所在行设置断点

    F4：运行到光标所在行

    F8：开始调试

    Shift + F8：停止调试

    F7：下一行代码

    Shift + F7：进入下一行代码

*/



using namespace std;

enum Base64Option {
   Base64Encoding = 0,
   Base64UrlEncoding = 1,

   KeepTrailingEquals = 0,
   OmitTrailingEquals = 2
};

extern string encode_base64(const  string sourceData, int options = Base64Encoding);
extern string decode_base64(const  std::string sourceData, int options = Base64Encoding);



string decryptQrcodeInfo(string byteArray,long timeStamp,string vCardPubkey){
    // get each field data
    int dataLength = byteArray.size();
    cout << dataLength << endl;

    if (dataLength && (dataLength >=3)  && (dataLength <= 280)){

         string STspec_field = byteArray.substr(0,2);
         string alg_field = byteArray.substr(2,2);
         string vcard_field = byteArray.substr(4,4);
         string biz_field = byteArray.substr(8,8);

         return biz_field;
         }
    else{
        return "error";
    }
}



int main()
{
    string byteArray = "01052389cdf36sde8730df32";
    long mstime = 1573465292;
    string pubKey = "ffeadfeade000000ecea00e";

    string biz_data = decryptQrcodeInfo(byteArray,mstime,pubKey);
    cout << biz_data << endl;

    cout << encode_base64( biz_data, 0) << endl;
//    cout << decode_base64( biz_data, 0) << endl;

    return 0;
}
