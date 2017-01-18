#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <windows.h>

#include <random>
using std::default_random_engine;
using std::normal_distribution;
using std::uniform_int_distribution;

#include <ctime>

void toclip(string &s)
{
    OpenClipboard(0);
	EmptyClipboard();
	HGLOBAL hg=GlobalAlloc(GMEM_MOVEABLE,s.size() + 1);

	if(!hg)
    {
		CloseClipboard();
		//cout << "text failed to enter clip" << endl;
		return;
	}

	memcpy(GlobalLock(hg),s.c_str(),s.size());
	GlobalUnlock(hg);
	SetClipboardData(CF_TEXT,hg);
	CloseClipboard();
	GlobalFree(hg);

	//cout << "memes successfully place in clip" << endl;
}

string randmotestr()
{
    const string azuki2 = ":azuki2:";               //0
    const string cinnamon2 = ":cinnamon2:";         //1
    const string cocochan2 = ":cocochan2:";         //2
    const string maple2 = ":maple2:";               //3
    const string chocola = ":chocola:";             //4
    const string maplechan = ":maplechan:";         //5
    const string owhunter = ":owhunter:";           //6
    const string coolsmile = ":coolsmile:";         //7
    const string B1 = ":B1:";                       //8
    const string amane_suou = ":amane_suou:";       //9
    const string sachi_komine = ":sachi_komine:";   //10
    const string SisterRam = ":SisterRam:";         //11
    const string Histoire = ":Histoire:";           //12
    const string hikari = ":hikari:";               //13
    const string itsumi = ":itsumi:";               //14


    string clipresult = "";

    default_random_engine dre(time(NULL));
    normal_distribution<double> dist(22.0, 4.0);    //mean 15, standard dev 5
    uniform_int_distribution<int> unidist(0, 14);   //from 0 to 14

    double emotenumfloat = dist(dre);
    int emotenum = (int)emotenumfloat;

    int toadd;
    for(int x = 0; x < emotenum; x++)
    {
        toadd = unidist(dre);
        switch(toadd)
        {
            case 0:
                clipresult = clipresult + azuki2;
                break;
            case 1:
                clipresult = clipresult + cinnamon2;
            case 2:
                clipresult = clipresult + cocochan2;
                break;
            case 3:
                clipresult = clipresult + maple2;
                break;
            case 4:
                clipresult = clipresult + chocola;
                break;
            case 5:
                clipresult = clipresult + maplechan;
                break;
            case 6:
                clipresult = clipresult + owhunter;
                break;
            case 7:
                clipresult = clipresult + coolsmile;
                break;
            case 8:
                clipresult = clipresult + B1;
                break;
            case 9:
                clipresult = clipresult + amane_suou;
                break;
            case 10:
                clipresult = clipresult + sachi_komine;
                break;
            case 11:
                clipresult = clipresult + SisterRam;
                break;
            case 12:
                clipresult = clipresult + Histoire;
                break;
            case 13:
                clipresult = clipresult + hikari;
                break;
            case 14:
                clipresult = clipresult + itsumi;
                break;

        }
    }

    return clipresult;
}



int main()
{
    string cliptext = randmotestr();



    toclip(cliptext);
}
