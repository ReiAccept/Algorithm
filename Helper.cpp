#include<iostream>
#include<fstream>

using namespace std;

bool DefaultMode;

int main(int argc , char* argv[])
{
    if(argc<3)
    {
        if(argc<2)
        {
            cout<<"Less Than 2 argc,EXIT"<<endl;
            return 0;
        }
        cout<<"Less Than 3 argc,Default Mode"<<endl;
        DefaultMode=true;
    }
    fstream file;
    if(!DefaultMode) file.open(argv[1],ios::binary|ios::in|ios::ate);//打开时指针在文件尾
    else file.open("DefaultCode.cpp",ios::binary|ios::in|ios::ate);
    int length=(int)file.tellg();
    char* imgData=new char[length];
    file.seekg(0);
    file.read(imgData,length);  //二进制只能用这个读
    
    fstream file2;
    if(!DefaultMode) file2.open(argv[2],ios::binary|ios::out);
    else file2.open(argv[1],ios::binary|ios::out);
    file2.write(imgData,length);   //二进制只能用这个写
    cout<<"Finished"<<endl;
    
    return 0;
}
