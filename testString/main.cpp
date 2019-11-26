#include <iostream>
#include <string>

using namespace std;
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
    return 0;
}
