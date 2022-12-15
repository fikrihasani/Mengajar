#include <stdio.h>
#include <string.h>

char S[100005];
	
int main(){
	int T;
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++){
		scanf("%s", S);
		int freq[26] = {};		//freq 26 alphabet 'a'-'z' masing-masing 0
		int freqPercobaanMax[26] = {};
		int freqPercobaanMin[26] = {};
		int len = strlen(S);
		int x;
		for(int i=0; i<len; i++){		//hitung freq per alphabet
			x = S[i] - 'a';				//temukan index per alphabet
			freq[x] += 1;
			freqPercobaanMax[x] = freqPercobaanMin[x] = freq[x];
		}
		
		//cari min max
		x = S[0] - 'a';			//set idxMin dan idxMax ada di index huruf pertama
		int idxMin = x, idxMax = x;
		for(int i=0; i<26; i++){
			if(freq[i] > 0){
				if(freq[i] > freq[idxMax]) idxMax = i;
				else if(freq[i] < freq[idxMin]) idxMin = i;
			}
		}
		//percobaan dengan max jadi 0 dan percobaan min jadi 0
		freqPercobaanMax[idxMax] = 0;
		freqPercobaanMin[idxMin] = 0;
		int countDiffMax = 0;
		int countDiffMin = 0;
		for(int i=0; i<26; i++){		//loop sebanyak alphabet 'a'-'z'
			//percobaan max jadi 0 maka bandingkan dengan yang di idxMin, klo dikurangi habis semua berarti frekuensi sudah sama rata
			if(freqPercobaanMax[i] > 0 && countDiffMax == 0){
				if(freqPercobaanMax[i] - freqPercobaanMax[idxMin] != 0){		//kalau dikurang tidak habis maka tidak sama frekuensinya
					countDiffMax = 1;
				}
			}
			//percobaan min jadi 0
			if(freqPercobaanMin[i] > 0 && countDiffMin == 0){
				if(freqPercobaanMin[i] - freqPercobaanMin[idxMax] != 0){
					countDiffMin = 1;
				}
			}
		}

		char alph[2];
		alph[0] = 'a' + idxMax;
		alph[1] = 'a' + idxMin;
		printf("Case %d: ", tc);
		if(freq[idxMax] == freq[idxMin])
            for(int i = 0; i<26; i++){
                if(freq[i] != 0){
                    printf("%c",'a'+i);
                }
            }							//artinya freq dari min ke max sudah rata, tidak perlu buang apapun
		else if(countDiffMax == 0 && countDiffMin == 1){
            for(int i = 0; i<26; i++){
                if(freq[i] != 0 && i!=idxMax){
                    printf("%c",'a'+i);
                }
            }						//frekuensi sama dengan buang max && tidak buang min
		}
		else if(countDiffMax == 1 && countDiffMin == 0){	
		//frekuensi sama dengan tidak buang max namun hanya buang min
            for(int i = 0; i<26; i++){
                if(freq[i] != 0 && i!=idxMin){
                    printf("%c",'a'+i);
                }
            }
		}
		else printf("N/A");						//1 1 freq min max tidak sama, tidak ada yang bisa dibuang
		
		putchar('\n');
	}
	return 0;
}

/*
 22322		max - 1
 22321		N/A
 22122		1
 33133		1
 221		2 atau 1
 2			N/A
 12			N/A
 22			N/A
 11 		N/A
 1122		N/A
*/
