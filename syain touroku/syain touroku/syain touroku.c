
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
	int syainNum;       //社員番号
	char Name[256]; //氏名
	int busyoCode;       //部署コード
}syain;


typedef struct {
	int  busyoCode2;      //部署コード
	char busyoName[256]; //部署名
}busyocode;


int syainExistence(int d);                                                    //1 社員番号 存在
int nameExistence(char* d);                                                   //1 氏名 存在
int busyocodeExistence(int aa);                                               //2 部署コード 存在
int busyonameExistence(char* aa);                                             //2 部署名 存在
char* syainList(syain syainsan[256], busyocode busyodesu[256], int syainnum); //3 社員 一覧
char* busyoList();                                                            //3 部署 一覧
int syainnumDeletion(int z);                                                  //4 社員番号 削除
int busyocodeDeletion(int z);                                                 //4 部署コード 削除
char* syainnumSearch(int b);                                                  //5 社員番号 検索
char* nameSearch(char* b);                                                    //5 氏名 検索
char* nameSearchOrder(char* b);                                               //5 氏名 検索 辞書順
char* busyocodeSearch(int b);                                                 //5 部署コード 検索
int syainChange(int z, char* c, int d);                                       //6 社員情報 変更
int busyoChange(int z);                                                       //6 部署 変更
char* busyoName(int aa, int syainnum, busyocode busyodesu[256]);              //7 部署名 出力
void syainSort(syain a[], int b);                                             //8 社員 並べ替え
void nameSort(syain a[], int b);                                              //8 氏名 並べ替え
void busyoSort(busyocode a[], int b);                                         //8 部署 並べ替え
int syainSplit(syain syainsan[256], busyocode busyodesu[256]);                //9 分解 社員
int busyoSplit(syain syainsan[256], busyocode busyodesu[256]);                //9 分解 部署


char syainTxt[256];
char busyoTxt[256];

int main() {

	int a;
	int b;
	char c[256];
	int z;
	int pp = 1;
	int qq = 1;
	int ss;
	FILE* tt;
	char uu[256];
	int ww = 1;
	int bbb = 1;
	int ccc;
	int ddd = 1;
	char eee;
	int fff = 1;
	int ggg;
	int hhh = 1;
	int iii = 1;
	char jjj;
	int kkk = 1;
	int lll = 1;
	int mmm;
	int nnn;
	errno_t d;
	int ooo = 1;
	char ppp[256];
	int qqq = 1;
	int rrr;
	int sss = 1;
	char e[256];
	int f = 1;
	int g;
	int h = 1;
	char ttt;
	syain syainsan[256] = { {0, "", 0} };
	busyocode busyodesu[256] = { {0, ""} };
	int syainnum;
	int busyonum;


	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);

	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	_splitpath_s(buffer, drive, _MAX_DRIVE, dir, _MAX_DIR, NULL, 0, NULL, 0);

	char filePath[MAX_PATH];
	_makepath_s(filePath, MAX_PATH, drive, dir, "syain.txt", NULL);

	char filePath2[MAX_PATH];
	_makepath_s(filePath2, MAX_PATH, drive, dir, "busyo.txt", NULL);

	strcpy_s(syainTxt, 256, filePath);
	strcpy_s(busyoTxt, 256, filePath2);


	syainnum = syainSplit(syainsan, busyodesu); //関数の引数には配列のサイズを指定する必要がない
	busyonum = busyoSplit(syainsan, busyodesu);


	while (h) {
		printf("メニュー[1.社員登録 2.社員変更 3.社員削除 4.社員検索 5.部署登録 6.部署削除 7.登録済社員一覧 8.登録済部署一覧 9.終了]\n");
		printf("メニュー番号入力：");

		scanf_s("%d", &a);

		switch (a) {

		case 1:
			printf("新しく社員を登録します。\n");

			pp = 1;

			while (pp) {
				printf("社員番号を入力：");
				scanf_s("%d", &b);

				//存在
				if (syainExistence(b) == 0) {
					printf("社員番号 %d は登録済です。\n", b);
					printf("＜登録済社員一覧＞\n%s", syainList(syainsan, busyodesu, syainnum));
				}
				else if (syainExistence(b) == 1) {
					pp = 0;
					break;
				}
			}
			printf("氏名を入力：");
			scanf_s("%s", c, 256);

			qq = 1;
			while (qq) {
				printf("部署[\n%s]\n", busyoList());
				printf("部署コードを入力：");
				scanf_s("%d", &z);

				//存在
				if (busyocodeExistence(z) == 0) {
					qq = 0;

					d = fopen_s(&tt, syainTxt, "a"); //追加書き込み
					if (d != 0) {
						printf("ファイルが開けません。\n");
						return 10;
					}

					fprintf(tt, "%d,", b); //社員番号
					fprintf(tt, "%s,", c); //氏名
					fprintf(tt, "%d\n", z); //部署コード

					fclose(tt);

					syainChange(b, c, z);

					printf("社員番号: %d , 氏名: %s , 部署コード: %d.%s 登録しました。\n", b, c, z, busyoName(z, syainnum, busyodesu));
				}
				else if (busyocodeExistence(z) == 1) {
					printf("部署コードが存在しません。\n");
					printf("メニューへ戻りますか？ 戻る場合はy、続ける場合はnを入力してください。\n");
					printf("yかnを入力：");
					scanf_s(" %c", &ttt, 1);

					if (ttt == 'y') {
						qq = 0;
						break;
					}
					else if (ttt == 'n') {
					}
				}
			}

			break;

		case 2:
			printf("社員情報の変更をします。\n");

			kkk = 1;
			while (kkk) {
				printf("社員番号を入力：");
				scanf_s("%d", &ss);

				//存在
				if (syainExistence(ss) == 0) {
					kkk = 0;

					printf("登録されているのは、%s", syainnumSearch(ss));

					printf("社員番号： %d の社員情報を変更します。\n", ss);

					printf("変更後の氏名を入力：");
					scanf_s("%s", e, 256);

					f = 1;
					while (f) {
						printf("部署[%s]\n", busyoList());
						printf("変更後の部署コードを入力：");
						scanf_s("%d", &g);

						//存在
						if (busyocodeExistence(g) == 0) {
							f = 0;
							break;
						}
						else if (busyocodeExistence(g) == 1) {
							printf("もう一度入力してください。\n");
						}
					}

					syainChange(ss, e, g);

					printf("社員番号: %d , 氏名: %s , 部署コード: %d.%s へ変更しました。\n", ss, e, g, busyoName(g, syainnum, busyodesu));

					break;
				}
				else if (syainExistence(ss) == 1) {
					printf("登録がありません。\n");
					printf("メニューへ戻りますか？ 戻る場合はy、続ける場合はnを入力してください。\n");
					printf("yかnを入力：");
					scanf_s(" %c", &ttt, 1);

					if (ttt == 'y') {
						kkk = 0;
						break;
					}
					else if (ttt == 'n') {
					}
				}
			}
			break;


		case 3:
			printf("社員の登録を削除します。\n");

			ddd = 1;
			while (ddd) {
				printf("社員番号を入力：");
				scanf_s("%d", &ccc);

				//存在
				if (syainExistence(ccc) == 0) {
					ddd = 0;

					printf("登録されているのは、%s", syainnumSearch(ccc));

					printf("削除しますか？ 削除する場合はy、削除しない場合はnを入力してください。\n");

					fff = 1;
					while (fff) {
						printf("yかnを入力：");
						scanf_s(" %c", &eee, 1);

						if (eee == 'y') {

							syainnumDeletion(ccc);

							printf("削除しました。\n");
							fff = 0;
							break;
						}
						else if (eee == 'n') {
							printf("キャンセルしました。\n");
							fff = 0;
							break;
						}
						else {
							printf("もう一度入力してください。\n");
						}
					}
				}

				else if (syainExistence(ccc) == 1) {
					printf("登録がありません。\n");
					printf("メニューへ戻りますか？ 戻る場合はy、続ける場合はnを入力してください。\n");
					printf("yかnを入力：");
					scanf_s(" %c", &ttt, 1);

					if (ttt == 'y') {
						ddd = 0;
						break;
					}
					else if (ttt == 'n') {
					}
				}
			}
			break;


		case 4:
			printf("検索します。\n");

			printf("メニュー[1.社員番号 2.氏名 3.部署コード]\n");
			printf("番号入力：");

			scanf_s("%d", &nnn);

			if (nnn != 1 && nnn != 2 && nnn != 3) {
				printf("もう一度入力してください。\n");
			}

			if (nnn == 1) {
				lll = 1;
				while (lll) {
					printf("社員番号を入力：");
					scanf_s("%d", &mmm);

					//存在
					if (syainExistence(mmm) == 0) {
						lll = 0;
						printf("%s", syainnumSearch(mmm));
						break;
					}
					else if (syainExistence(mmm) == 1) {
						printf("登録がありません。\n");
						printf("メニューへ戻りますか？ 戻る場合はy、続ける場合はnを入力してください。\n");
						printf("yかnを入力：");
						scanf_s(" %c", &ttt, 1);

						if (ttt == 'y') {
							lll = 0;
							break;
						}
						else if (ttt == 'n') {
						}
					}
				}
			}

			if (nnn == 2) {
				ooo = 1;
				while (ooo) {
					printf("氏名を入力：");
					scanf_s("%s", ppp, 256);

					//存在
					if (nameExistence(ppp) == 0) {
						ooo = 0;
						printf("%s", nameSearch(ppp));

						printf("氏名を辞書順にしますか？ する場合はy、しない場合はnを入力してください。\n");
						printf("yかnを入力：");
						scanf_s(" %c", &ttt, 1);

						if (ttt == 'y') {
							printf("%s", nameSearchOrder(ppp));
							break;
						}
						else if (ttt == 'n') {
							break;
						}

						break;
					}
					else if (nameExistence(ppp) == 1) {
						printf("登録がありません。\n");
						printf("メニューへ戻りますか？ 戻る場合はy、続ける場合はnを入力してください。\n");
						printf("yかnを入力：");
						scanf_s(" %c", &ttt, 1);

						if (ttt == 'y') {
							ooo = 0;
							break;
						}
						else if (ttt == 'n') {
						}
					}
				}
			}

			if (nnn == 3) {
				qqq = 1;
				while (qqq) {
					printf("部署コードを入力：");
					scanf_s("%d", &rrr);

					//存在
					if (busyocodeExistence(rrr) == 0) {
						qqq = 0;

						printf("部署: %d.", rrr);
						printf("%sです。\n", busyocodeSearch(rrr));

						break;
					}
					else if (busyocodeExistence(rrr) == 1) {
						printf("登録がありません。\n");
						printf("メニューへ戻りますか？ 戻る場合はy、続ける場合はnを入力してください。\n");
						printf("yかnを入力：");
						scanf_s(" %c", &ttt, 1);

						if (ttt == 'y') {
							ooo = 0;
							break;
						}
						else if (ttt == 'n') {
						}
					}
				}
			}

			break;


		case 5:
			printf("新しく部署を登録します。\n");

			ww = 1;
			while (ww) {
				printf("部署コードを入力：");
				scanf_s("%d", &ss);

				//存在
				if (busyocodeExistence(ss) == 0) {
					printf("部署コード %d は登録済です。\n", ss);
					printf("＜登録済部署一覧＞\n%s", busyoList());
				}
				else if (busyocodeExistence(ss) == 1) {
					ww = 0;
					break;
				}
			}

			bbb = 1;
			while (bbb) {
				printf("部署名を入力：");
				scanf_s("%s", uu, (unsigned)_countof(uu)); //unsignedは符号なし整数型のキーワード、countofは配列の要素数を取得するためのマクロ

				//存在
				if (busyonameExistence(uu) == 0) {
					printf("部署名 %s は登録済です。\n", uu);
				}
				else if (busyonameExistence(uu) == 1) {
					bbb = 0;

				}
			}

			d = fopen_s(&tt, busyoTxt, "a"); //追加書き込み
			if (d != 0) {
				printf("ファイルが開けません。\n");
				return 10;
			}

			fprintf(tt, "%d.", ss); //部署コード
			fprintf(tt, "%s\n", uu); //部署名

			fclose(tt);

			busyoChange(ss);

			printf("部署コード: %d , 部署名： %s 登録しました。\n", ss, uu);

			break;


		case 6:
			printf("部署の登録を削除します。\n");

			hhh = 1;
			while (hhh) {
				printf("部署コードを入力：");
				scanf_s("%d", &ggg);

				//存在
				if (busyocodeExistence(ggg) == 0) {
					hhh = 0;

					printf("削除しますか？ 削除する場合はy、削除しない場合はnを入力してください。\n");

					iii = 1;
					while (iii) {
						printf("yかnを入力：");
						scanf_s(" %c", &jjj, 1);

						if (jjj == 'y') {

							busyocodeDeletion(ggg);

							printf("削除しました。\n");
							iii = 0;
							break;
						}
						else if (jjj == 'n') {
							printf("キャンセルしました。\n");
							iii = 0;
							break;
						}
						else {
							printf("もう一度入力してください。\n");
						}
					}
					hhh = 0;
					break;
				}
				else if (busyocodeExistence(ggg) == 1) {
					printf("登録がありません。\n");
					printf("メニューへ戻りますか？ 戻る場合はy、続ける場合はnを入力してください。\n");
					printf("yかnを入力：");
					scanf_s(" %c", &ttt, 1);

					if (ttt == 'y') {
						hhh = 0;
						break;
					}
					else if (ttt == 'n') {
					}
				}
			}
			break;

		case 7:
			printf("＜登録済社員一覧＞\n社員番号   氏名      部署\n%s", syainList(syainsan, busyodesu, syainnum));
			break;

		case 8:
			printf("＜登録済部署一覧＞\n部署コード  部署名\n%s", busyoList());
			break;

		case 9:
			printf("終了しました。\n");

			h = 0;
			break;

		default:
			printf("もう一度入力してください。\n");

			break;
		}
	}
}


//1.社員のデータが存在する・しない関数

//社員番号 存在
int syainExistence(int d) {

	int z; //回数
	syain syainsan[256];
	busyocode busyodesu[256];

	for (z = 0; z < syainSplit(syainsan, busyodesu); z++) {
		if (d == syainsan[z].syainNum) {
			return 0;
		}
	}
	return 1;
}


//氏名 存在
int nameExistence(char* d) {

	int z; //回数
	syain syainsan[256];
	busyocode busyodesu[256];

	for (z = 0; z < syainSplit(syainsan, busyodesu); z++) {
		if (strncmp(syainsan[z].Name, d, strlen(d)) == 0) {
			return 0;
		}
	}

	return 1;
}

//2.部署コードが存在する・しない関数

//部署コード 存在
int busyocodeExistence(int aa) {

	int z; //回数
	syain syainsan[256];
	busyocode busyodesu[256];

	for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
		if (aa == busyodesu[z].busyoCode2) {
			return 0;
		}
	}
	return 1;
}


//部署名 存在
int busyonameExistence(char* aa) {

	int z; //回数
	syain syainsan[256];
	busyocode busyodesu[256];

	for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
		if (strcmp(aa, busyodesu[z].busyoName) == 0) { //文字列が等しいと0を返す
			return 0;
		}
	}
	return 1;
}
//
//
//3.一覧関数

// 社員 一覧
char* syainList(syain syainsan[256], busyocode busyodesu[256], int syainnum) { //社員構造体、部署構造体、社員人数+1

	int z; //回数
	static char y[256]; //1人
	static char n[1000]; //全員

	memset(&y[0], '\0', sizeof(y));
	memset(&n[0], '\0', sizeof(n));

	for (z = 0; z < syainnum; z++) {

		sprintf_s(y, sizeof(y), "%-11d%-10s%d.%s\n", syainsan[z].syainNum, syainsan[z].Name, syainsan[z].busyoCode, busyoName(syainsan[z].busyoCode, syainnum, busyodesu));

		strcat_s(n, sizeof(n), y);

	}
	return n;
}
//
//
// 部署コード 一覧

char* busyoList() {

	int z; //回数
	syain syainsan[256];
	busyocode busyodesu[256];
	static char y[256]; //1つ
	static char n[1000]; //全部

	memset(&y[0], '\0', sizeof(y));
	memset(&n[0], '\0', sizeof(n));

	for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {

		sprintf_s(y, sizeof(y), "%-12d%s\n", busyodesu[z].busyoCode2, busyodesu[z].busyoName);

		strcat_s(n, sizeof(n), y);

	}
	return n;
}


//char* busyoList() {
//
//	FILE* bb; //ファイル
//	char u[256]; //保存する配列
//	static char y[256]; //"部署コードが存在しません。"を入れる
//	static char ll[256]; //登録されている部署コード全部入れる
//	size_t v;
//	errno_t a;
//	static char k[256];
//
//	a = fopen_s(&bb, busyoTxt, "a"); //読み込み
//	if (a != 0) {
//		strcpy_s(k, 256, "ファイルが開けません。\n");
//		return k;
//	}
//
//	fclose(bb);
//
//	a = fopen_s(&bb, busyoTxt, "r"); //読み込み
//	if (a != 0) {
//		strcpy_s(k, 256, "ファイルが開けません。\n");
//		return k;
//	}
//
//	memset(&u, '\0', 256);
//
//	v = fread(u, sizeof(char), 255, bb);
//
//	u[v] = '\0';
//
//	fclose(bb);
//
//	if (strlen(u) == 0) {
//
//		strcpy_s(y, 256, "部署コードが存在しません。\n");
//
//		return y;
//	}
//	else {
//		strcpy_s(ll, 256, u);
//
//		return ll;
//	}
//}


//4.削除関数

//社員番号 削除
int syainnumDeletion(int z) {

	FILE* b; //ファイル
	errno_t a;
	int h; //回数
	syain syainsan[256];
	busyocode busyodesu[256];

	a = fopen_s(&b, syainTxt, "w+"); //更新書き込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	for (h = 0; h < syainSplit(syainsan, busyodesu); h++) {
		if (z != syainsan[h].syainNum) {

			fprintf(b, "%d,%s,%d\n", syainsan[h].syainNum, syainsan[h].Name, syainsan[h].busyoCode);

		}
	}

	fclose(b);

	return 0;
}

//部署コード 削除
int busyocodeDeletion(int z) {

	FILE* b; //ファイル
	errno_t a;
	int h; //回数
	syain syainsan[256];
	busyocode busyodesu[256];

	a = fopen_s(&b, busyoTxt, "w+"); //更新書き込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	for (h = 0; h < busyoSplit(syainsan, busyodesu); h++) {
		if (z != busyodesu[h].busyoCode2) {

			fprintf(b, "%d.%s\n", busyodesu[h].busyoCode2, busyodesu[h].busyoName);

		}
	}

	fclose(b);

	return 0;
}

//5.検索関数

//社員番号から検索
char* syainnumSearch(int b) {

	int zz; //回数
	int z; //回数
	static char y[256]; //完成
	static char n[256]; //一部
	static char p[256]; //エラー
	syain syainsan[256];
	busyocode busyodesu[256];

	memset(&y[0], '\0', sizeof(y));
	memset(&n[0], '\0', sizeof(n));
	memset(&p[0], '\0', sizeof(p));

	for (zz = 0; zz < syainSplit(syainsan, busyodesu); zz++) {
		//社員番号bと社員番号一致するか
		if (b == syainsan[zz].syainNum) {

			sprintf_s(y, sizeof(y), "社員番号: %d , 氏名: %s , 部署: %d", syainsan[zz].syainNum, syainsan[zz].Name, syainsan[zz].busyoCode);

		}
	}

	for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
		//部署コードと部署のコード一致するか
		if (zz > 0 && syainsan[zz - 1].busyoCode == busyodesu[z].busyoCode2) { //zz++ されていて 1多いから -1する、zz が0の場合にはこの条件を実行しないように zz > 0

			sprintf_s(n, sizeof(n), ".%s です。\n", busyodesu[z].busyoName);

			strcat_s(y, sizeof(y), n);

			return y;
		}
	}

	strcpy_s(p, sizeof(p), "エラーが発生しました。\n");
	return p;
}


//氏名から検索
char* nameSearch(char* b) {

	int zz; //回数
	int z; //回数
	static char y[256]; //完成
	static char n[256]; //一部
	syain syainsan[256];
	busyocode busyodesu[256];

	memset(&y[0], '\0', sizeof(y));
	memset(&n[0], '\0', sizeof(n));

	for (zz = 0; zz < syainSplit(syainsan, busyodesu); zz++) {
		//氏名bと氏名一致するか
		if (strncmp(syainsan[zz].Name, b, strlen(b)) == 0) {

			sprintf_s(y, sizeof(y), "社員番号: %d , 氏名: %s , 部署: %d", syainsan[zz].syainNum, syainsan[zz].Name, syainsan[zz].busyoCode);

			strncat_s(n, sizeof(n), y, sizeof(n) - strlen(n) - 1);

			for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
				if (syainsan[zz].busyoCode == busyodesu[z].busyoCode2) {

					sprintf_s(y, sizeof(y), ".%s です。\n", busyodesu[z].busyoName);

					strncat_s(n, sizeof(n), y, sizeof(n) - strlen(n) - 1);

				}
			}
		}
	}

	return n;
}


//氏名から検索
char* nameSearchOrder(char* b) {

	int zz; //回数
	int z; //回数
	static char y[256]; //一部
	static char n[256]; //完成
	syain syainsan[256];
	busyocode busyodesu[256];

	syainSplit(syainsan, busyodesu);

	nameSort(syainsan, syainSplit(syainsan, busyodesu));

	memset(&y[0], '\0', sizeof(y));
	memset(&n[0], '\0', sizeof(n));

	for (zz = 0; zz < syainSplit(syainsan, busyodesu); zz++) {
		//氏名bと氏名一致するか
		if (strncmp(syainsan[zz].Name, b, strlen(b)) == 0) {

			sprintf_s(y, sizeof(y), "社員番号: %d , 氏名: %s , 部署: %d", syainsan[zz].syainNum, syainsan[zz].Name, syainsan[zz].busyoCode);

			strncat_s(n, sizeof(n), y, sizeof(n) - strlen(n) - 1);

			for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
				if (syainsan[zz].busyoCode == busyodesu[z].busyoCode2) {

					sprintf_s(y, sizeof(y), ".%s です。\n", busyodesu[z].busyoName);

					strncat_s(n, sizeof(n), y, sizeof(n) - strlen(n) - 1);

				}
			}
		}
	}

	return n;
}


//部署コードから全員
char* busyocodeSearch(int b) {

	int zz; //回数
	int z; //回数
	static char y[256]; //一部
	static char m[256]; //一部
	static char n[256]; //完成
	static char p[256]; //エラー
	syain syainsan[256];
	busyocode busyodesu[256];

	memset(&y[0], '\0', sizeof(y));
	memset(&m[0], '\0', sizeof(m));
	memset(&n[0], '\0', sizeof(n));
	memset(&p[0], '\0', sizeof(p));

	//部署コードbと部署コード一致するか
	for (zz = 0; zz < syainSplit(syainsan, busyodesu); zz++) {
		if (b == syainsan[zz].busyoCode) {

			sprintf_s(y, sizeof(y), "社員番号: %d , 氏名: %s\n", syainsan[zz].syainNum, syainsan[zz].Name); //sprintf_sは変数を文字列に変換して挿入

			strcat_s(m, sizeof(m), y);

		}
	}

	//社員の部署コードと部署の部署コード一致するか
	for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
		if (b == busyodesu[z].busyoCode2) {

			sprintf_s(n, sizeof(n), "%s へ登録されているのは\n", busyodesu[z].busyoName);

			strcat_s(n, sizeof(n), m);

			return n;
		}
	}

	strcpy_s(p, sizeof(p), "エラーが発生しました。\n");
	return p;
}


//6.社員情報 変更
int syainChange(int z, char* c, int d) {

	FILE* b; //ファイル
	errno_t a;
	int h; //回数
	syain syainsan[256];
	busyocode busyodesu[256];
	int e;

	e = syainSplit(syainsan, busyodesu);

	syainSort(syainsan, e);

	//一致したら変更したものを書き込む、該当しないものはそのまま全て書き込む
	a = fopen_s(&b, syainTxt, "w+"); //書き込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	for (h = 0; h < e; h++) {

		if (z == syainsan[h].syainNum) {

			strcpy_s(syainsan[h].Name, 256, c);
			syainsan[h].busyoCode = d;

			fprintf(b, "%d,%s,%d\n", z, c, d);
		}

		if (z != syainsan[h].syainNum) {

			fprintf(b, "%d,%s,%d\n", syainsan[h].syainNum, syainsan[h].Name, syainsan[h].busyoCode);

		}
	}

	fclose(b);

	return 0;
}


//部署 変更
int busyoChange(int z) {

	FILE* b; //ファイル
	errno_t a;
	int h; //回数
	syain syainsan[256];
	busyocode busyodesu[256];
	int e;

	e = busyoSplit(syainsan, busyodesu);

	busyoSort(busyodesu, e);

	a = fopen_s(&b, busyoTxt, "w+"); //更新書き込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	for (h = 0; h < e; h++) {

		fprintf(b, "%d.%s\n", busyodesu[h].busyoCode2, busyodesu[h].busyoName);
	}

	fclose(b);

	return 0;
}


//7.部署名 出力
char* busyoName(int aa, int syainnum, busyocode busyodesu[256]) { //社員人数構造体の部署コード、社員人数+1、部署構造体

	int z; //回数
	static char y[256];
	static char n[256];

	memset(&y[0], '\0', sizeof(y));
	memset(&n[0], '\0', sizeof(n));

	for (z = 0; z < syainnum; z++) {
		if (aa == busyodesu[z].busyoCode2) {

			sprintf_s(y, sizeof(y), "%s", busyodesu[z].busyoName);
			return y;
		}
	}
	strcpy_s(n, 256, "エラーが発生しました。");
	return n;
}


//8.並べ替え関数 バブルソート

//社員番号 並べ替え
void syainSort(syain a[], int b) { //構造体、構造体の何番目

	int c; //何回
	int d; //何回
	syain e; //構造体空

	for (c = 0; c < b - 1; c++) {
		for (d = 0; d < b - 1; d++) {
			if (a[d].syainNum > a[d + 1].syainNum) {
				e = a[d];
				a[d] = a[d + 1];
				a[d + 1] = e;
			}
		}
	}
}


//氏名 並べ替え
void nameSort(syain a[], int b) { //構造体、構造体の何番目

	int c; //何回
	int d; //何回
	syain e; //構造体空

	for (c = 0; c < b - 1; c++) {
		for (d = 0; d < b - 1; d++) {
			if (strcmp(a[d].Name, a[d + 1].Name) > 0) { //strcmpは文字列が等しいか、またはどちらが辞書順で先かを比較
				e = a[d];
				a[d] = a[d + 1];
				a[d + 1] = e;
			}
		}
	}
}


//部署コード 並べ替え
void busyoSort(busyocode a[], int b) { //構造体、構造体の何番目

	int c; //何回
	int d; //何回
	busyocode e; //構造体空

	for (c = 0; c < b - 1; c++) {
		for (d = 0; d < b - 1; d++) {
			if (a[d].busyoCode2 > a[d + 1].busyoCode2) {
				e = a[d];
				a[d] = a[d + 1];
				a[d + 1] = e;
			}
		}
	}
}


//並べ替え関数 選択ソート

//社員番号 並べ替え
//void syainSort(syain a[], int b) { //構造体、構造体の何番目
//
//	int c; //何回
//	int d; //何回
//	int f; //最小
//	syain e; //構造体空
//
//	for (c = 0; c < b - 1; c++) {
//		f = c;
//
//		for (d = c + 1; d < b; d++) {
//			if (a[d].syainNum < a[f].syainNum) {
//				f = d;
//			}
//		}
//
//		e = a[c];
//		a[c] = a[f];
//		a[f] = e;
//	}
//}


//9.分解関数

//分解 社員
int syainSplit(syain syainsan[256], busyocode busyodesu[256]) {

	FILE* txt; //ファイル
	errno_t a;
	static char nop[256]; //ファイルが開けません。
	char ichigyou[256]; //1行保存する配列
	int d; //回数
	char bangou[256]; //1文字ずつ入れる配列
	int suji; //数字にしたものを入れる　
	int e; //回数
	char simei[256]; //1文字ずつ入れる配列
	char busyobangou[256]; //1文字ずつ入れる配列
	int i; //回数
	int suji2; //数字にしたものを入れる
	int syainnum;

	char ichigyou2[256]; //1行保存する配列
	char bangou2[256];
	char busyomei[256];
	int busyonum;

	syainnum = 0;
	busyonum = 0;

	a = fopen_s(&txt, syainTxt, "a"); //読み込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	fclose(txt);

	a = fopen_s(&txt, syainTxt, "r"); //読み込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	while (fgets(ichigyou, 256, txt) != NULL) {  //(1行保存する配列、配列のサイズ、どのファイル)

		memset(&bangou[0], '\0', sizeof(bangou));
		memset(&simei[0], '\0', sizeof(simei));
		memset(&busyobangou[0], '\0', sizeof(busyobangou));

		//社員番号
		for (d = 0; ichigyou[d] != ','; d++) {
			bangou[d] = ichigyou[d];
		}

		suji = atoi(bangou);
		syainsan[syainnum].syainNum = suji;

		//氏名
		for (d = d + 1, e = 0; ichigyou[d] != ','; d++, e++) {
			simei[e] = ichigyou[d];
		}

		strcpy_s(syainsan[syainnum].Name, 256, &simei[0]);


		//部署コード
		for (d = d + 1, i = 0; ichigyou[d] != '\0' && ichigyou[d] != '\n'; d++, i++) {
			busyobangou[i] = ichigyou[d];
		}

		suji2 = atoi(busyobangou);
		syainsan[syainnum].busyoCode = suji2;

		syainnum++;

	}

	fclose(txt);


	a = fopen_s(&txt, busyoTxt, "a"); //読み込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	fclose(txt);

	a = fopen_s(&txt, busyoTxt, "r"); //読み込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	while (fgets(ichigyou2, 256, txt) != NULL) {  //(1行保存する配列、配列のサイズ、どのファイル)

		memset(&bangou2[0], '\0', sizeof(bangou2));
		memset(&busyomei[0], '\0', sizeof(busyomei));

		//部署コード
		for (d = 0; ichigyou2[d] != '.'; d++) {
			bangou2[d] = ichigyou2[d];
		}

		suji = atoi(bangou2);
		busyodesu[busyonum].busyoCode2 = suji;

		//部署名
		for (d = d + 1, e = 0; ichigyou2[d] != '\0' && ichigyou2[d] != '\n'; d++, e++) {
			busyomei[e] = ichigyou2[d];
		}

		strcpy_s(busyodesu[busyonum].busyoName, 256, &busyomei[0]);

		busyonum++;

	}

	fclose(txt);

	return syainnum;
}


//分解 部署
int busyoSplit(syain syainsan[256], busyocode busyodesu[256]) {

	FILE* txt; //ファイル
	errno_t a;
	static char nop[256]; //ファイルが開けません。
	char ichigyou[256]; //1行保存する配列
	int d; //回数
	char bangou[256]; //1文字ずつ入れる配列
	int suji; //数字にしたものを入れる　
	int e; //回数
	char simei[256]; //1文字ずつ入れる配列
	char busyobangou[256]; //1文字ずつ入れる配列
	int i; //回数
	int suji2; //数字にしたものを入れる
	int syainnum;

	char ichigyou2[256]; //1行保存する配列
	char bangou2[256];
	char busyomei[256];
	int busyonum;

	syainnum = 0;
	busyonum = 0;

	a = fopen_s(&txt, syainTxt, "a"); //読み込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	fclose(txt);

	a = fopen_s(&txt, syainTxt, "r"); //読み込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	while (fgets(ichigyou, 256, txt) != NULL) {  //(1行保存する配列、配列のサイズ、どのファイル)

		memset(&bangou[0], '\0', sizeof(bangou));
		memset(&simei[0], '\0', sizeof(simei));
		memset(&busyobangou[0], '\0', sizeof(busyobangou));

		//社員番号
		for (d = 0; ichigyou[d] != ','; d++) {
			bangou[d] = ichigyou[d];
		}

		suji = atoi(bangou);
		syainsan[syainnum].syainNum = suji;

		//氏名
		for (d = d + 1, e = 0; ichigyou[d] != ','; d++, e++) {
			simei[e] = ichigyou[d];
		}

		strcpy_s(syainsan[syainnum].Name, 256, &simei[0]);


		//部署コード
		for (d = d + 1, i = 0; ichigyou[d] != '\0' && ichigyou[d] != '\n'; d++, i++) {
			busyobangou[i] = ichigyou[d];
		}

		suji2 = atoi(busyobangou);
		syainsan[syainnum].busyoCode = suji2;

		syainnum++;

	}

	fclose(txt);


	a = fopen_s(&txt, busyoTxt, "a"); //読み込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	fclose(txt);

	a = fopen_s(&txt, busyoTxt, "r"); //読み込み
	if (a != 0) {
		printf("ファイルが開けません。\n");
		return 10;
	}

	while (fgets(ichigyou2, 256, txt) != NULL) {  //(1行保存する配列、配列のサイズ、どのファイル)

		memset(&bangou2[0], '\0', sizeof(bangou2));
		memset(&busyomei[0], '\0', sizeof(busyomei));

		//部署コード
		for (d = 0; ichigyou2[d] != '.'; d++) {
			bangou2[d] = ichigyou2[d];
		}

		suji = atoi(bangou2);
		busyodesu[busyonum].busyoCode2 = suji;

		//部署名
		for (d = d + 1, e = 0; ichigyou2[d] != '\0' && ichigyou2[d] != '\n'; d++, e++) {
			busyomei[e] = ichigyou2[d];
		}

		strcpy_s(busyodesu[busyonum].busyoName, 256, &busyomei[0]);

		busyonum++;

	}

	fclose(txt);

	return busyonum;
}