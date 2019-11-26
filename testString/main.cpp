#include <iostream>
#include <string>

/*
    ��סCtrl�����������֣��Ŵ����С���塣

    Ctrl+Shift+Cע�͵���ǰ�л�ѡ�в��֣�Ctrl+Shift+X���ע�͡�

    Ctrl+T ����һ�н���λ�á�

    ��סCtrl���϶�ѡ�����ݣ����ⲿ����������λ�ø���һ�顣

    ��סAlt�ٷ���������ƶ��������������ƶ���

    Tab��������ǰ�л�ѡ�п顣

    Shift+Tab������������

    д��ؼ��ʣ��磺if��for��while���󣬰�Ctrl+J�Զ���ȫ��ʽ������ʽ�͹ؼ��ʿ����Լ�ȥ�༭�������ã�

    Ctrl+Z��������

    Ctrl+Shift+Z�����ڳ�����

    Ctrl+C�����ơ�

    Ctrl+V��ճ����

    Ctrl+X�����С�

    Ctrl+A��ȫѡ��

    2.���������в��֣�
    Ctrl + F9������
    Ctrl + F10�������ϴγɹ������ĳ���
    Ctrl +��Shift + F9:���뵱ǰ�ļ��������ǵ�ǰ�򿪵Ĺ�����Ŀ��
    F9�����벢���е�ǰ���루�������������ʾ������������У�
    F8��debug
    F10:ȫ��
    Ctrl + C����ֹ�������еĳ���
    Ctrl + Z����ֹ����

    3.���Բ��֣�

    F5���ڵ�ǰ������������öϵ�

    F4�����е����������

    F8����ʼ����

    Shift + F8��ֹͣ����

    F7����һ�д���

    Shift + F7��������һ�д���

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
