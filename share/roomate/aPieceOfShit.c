/*从身份证号码中提取生日信息。

要求把文件id.txt中若干个人的姓名和身份证号码显示在屏幕上。然后，将其生日信息提取出来存放到一字符串中，并将所提取的姓名和生日信息写入另一个文件bd.txt。


id.txt


要求运行结果如下所示：

文件id.txt中的内容为：

张红

310110199609093420

王伟

310110199706151321

陶涛

220120199811086713


所提取的生日信息为：

张红 1996年9月9日

王伟 1997年6月15日

陶涛 1998年11月8日


*/
#include <stdio.h>

int main(){

    char *name[3];//字符串数组存名字

    int birth[3];//整形数组存生日

    //读id.txt

    FILE *id=fopen("id.txt","r");

    for(int i=0;i<3;i++){

        fscanf(id,"%s",name+i*sizeof(name));

        fseek(id,8,1);//定位到身份证表示生日的位

        fscanf(id,"%8d",&birth[i]);

        fseek(id,4,1);//定位到下一人

    }

    fclose(id);

    //写bd.txt

    FILE *bd=fopen("bd.txt","w");

    for(int i=0;i<3;i++){

        fprintf(bd,"%s %d年%d月%d日\n",name+i*sizeof(name),birth[i]/10000,birth[i]%10000/100,birth[i]%100);

    }

    fclose(bd);

    return 0;

}