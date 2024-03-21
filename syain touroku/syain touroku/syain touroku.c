
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct {
	int syainNum;       //�Ј��ԍ�
	char Name[256]; //����
	int busyoCode;       //�����R�[�h
}syain;


typedef struct {
	int  busyoCode2;      //�����R�[�h
	char busyoName[256]; //������
}busyocode;


int syainExistence(int d);                                                    //1 �Ј��ԍ� ����
int nameExistence(char* d);                                                   //1 ���� ����
int busyocodeExistence(int aa);                                               //2 �����R�[�h ����
int busyonameExistence(char* aa);                                             //2 ������ ����
char* syainList(syain syainsan[256], busyocode busyodesu[256], int syainnum); //3 �Ј� �ꗗ
char* busyoList();                                                            //3 ���� �ꗗ
int syainnumDeletion(int z);                                                  //4 �Ј��ԍ� �폜
int busyocodeDeletion(int z);                                                 //4 �����R�[�h �폜
char* syainnumSearch(int b);                                                  //5 �Ј��ԍ� ����
char* nameSearch(char* b);                                                    //5 ���� ����
char* nameSearchOrder(char* b);                                               //5 ���� ���� ������
char* busyocodeSearch(int b);                                                 //5 �����R�[�h ����
int syainChange(int z, char* c, int d);                                       //6 �Ј���� �ύX
int busyoChange(int z);                                                       //6 ���� �ύX
char* busyoName(int aa, int syainnum, busyocode busyodesu[256]);              //7 ������ �o��
void syainSort(syain a[], int b);                                             //8 �Ј� ���בւ�
void nameSort(syain a[], int b);                                              //8 ���� ���בւ�
void busyoSort(busyocode a[], int b);                                         //8 ���� ���בւ�
int syainSplit(syain syainsan[256], busyocode busyodesu[256]);                //9 ���� �Ј�
int busyoSplit(syain syainsan[256], busyocode busyodesu[256]);                //9 ���� ����


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


	syainnum = syainSplit(syainsan, busyodesu); //�֐��̈����ɂ͔z��̃T�C�Y���w�肷��K�v���Ȃ�
	busyonum = busyoSplit(syainsan, busyodesu);


	while (h) {
		printf("���j���[[1.�Ј��o�^ 2.�Ј��ύX 3.�Ј��폜 4.�Ј����� 5.�����o�^ 6.�����폜 7.�o�^�ώЈ��ꗗ 8.�o�^�ϕ����ꗗ 9.�I��]\n");
		printf("���j���[�ԍ����́F");

		scanf_s("%d", &a);

		switch (a) {

		case 1:
			printf("�V�����Ј���o�^���܂��B\n");

			pp = 1;

			while (pp) {
				printf("�Ј��ԍ�����́F");
				scanf_s("%d", &b);

				//����
				if (syainExistence(b) == 0) {
					printf("�Ј��ԍ� %d �͓o�^�ςł��B\n", b);
					printf("���o�^�ώЈ��ꗗ��\n%s", syainList(syainsan, busyodesu, syainnum));
				}
				else if (syainExistence(b) == 1) {
					pp = 0;
					break;
				}
			}
			printf("��������́F");
			scanf_s("%s", c, 256);

			qq = 1;
			while (qq) {
				printf("����[\n%s]\n", busyoList());
				printf("�����R�[�h����́F");
				scanf_s("%d", &z);

				//����
				if (busyocodeExistence(z) == 0) {
					qq = 0;

					d = fopen_s(&tt, syainTxt, "a"); //�ǉ���������
					if (d != 0) {
						printf("�t�@�C�����J���܂���B\n");
						return 10;
					}

					fprintf(tt, "%d,", b); //�Ј��ԍ�
					fprintf(tt, "%s,", c); //����
					fprintf(tt, "%d\n", z); //�����R�[�h

					fclose(tt);

					syainChange(b, c, z);

					printf("�Ј��ԍ�: %d , ����: %s , �����R�[�h: %d.%s �o�^���܂����B\n", b, c, z, busyoName(z, syainnum, busyodesu));
				}
				else if (busyocodeExistence(z) == 1) {
					printf("�����R�[�h�����݂��܂���B\n");
					printf("���j���[�֖߂�܂����H �߂�ꍇ��y�A������ꍇ��n����͂��Ă��������B\n");
					printf("y��n����́F");
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
			printf("�Ј����̕ύX�����܂��B\n");

			kkk = 1;
			while (kkk) {
				printf("�Ј��ԍ�����́F");
				scanf_s("%d", &ss);

				//����
				if (syainExistence(ss) == 0) {
					kkk = 0;

					printf("�o�^����Ă���̂́A%s", syainnumSearch(ss));

					printf("�Ј��ԍ��F %d �̎Ј�����ύX���܂��B\n", ss);

					printf("�ύX��̎�������́F");
					scanf_s("%s", e, 256);

					f = 1;
					while (f) {
						printf("����[%s]\n", busyoList());
						printf("�ύX��̕����R�[�h����́F");
						scanf_s("%d", &g);

						//����
						if (busyocodeExistence(g) == 0) {
							f = 0;
							break;
						}
						else if (busyocodeExistence(g) == 1) {
							printf("������x���͂��Ă��������B\n");
						}
					}

					syainChange(ss, e, g);

					printf("�Ј��ԍ�: %d , ����: %s , �����R�[�h: %d.%s �֕ύX���܂����B\n", ss, e, g, busyoName(g, syainnum, busyodesu));

					break;
				}
				else if (syainExistence(ss) == 1) {
					printf("�o�^������܂���B\n");
					printf("���j���[�֖߂�܂����H �߂�ꍇ��y�A������ꍇ��n����͂��Ă��������B\n");
					printf("y��n����́F");
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
			printf("�Ј��̓o�^���폜���܂��B\n");

			ddd = 1;
			while (ddd) {
				printf("�Ј��ԍ�����́F");
				scanf_s("%d", &ccc);

				//����
				if (syainExistence(ccc) == 0) {
					ddd = 0;

					printf("�o�^����Ă���̂́A%s", syainnumSearch(ccc));

					printf("�폜���܂����H �폜����ꍇ��y�A�폜���Ȃ��ꍇ��n����͂��Ă��������B\n");

					fff = 1;
					while (fff) {
						printf("y��n����́F");
						scanf_s(" %c", &eee, 1);

						if (eee == 'y') {

							syainnumDeletion(ccc);

							printf("�폜���܂����B\n");
							fff = 0;
							break;
						}
						else if (eee == 'n') {
							printf("�L�����Z�����܂����B\n");
							fff = 0;
							break;
						}
						else {
							printf("������x���͂��Ă��������B\n");
						}
					}
				}

				else if (syainExistence(ccc) == 1) {
					printf("�o�^������܂���B\n");
					printf("���j���[�֖߂�܂����H �߂�ꍇ��y�A������ꍇ��n����͂��Ă��������B\n");
					printf("y��n����́F");
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
			printf("�������܂��B\n");

			printf("���j���[[1.�Ј��ԍ� 2.���� 3.�����R�[�h]\n");
			printf("�ԍ����́F");

			scanf_s("%d", &nnn);

			if (nnn != 1 && nnn != 2 && nnn != 3) {
				printf("������x���͂��Ă��������B\n");
			}

			if (nnn == 1) {
				lll = 1;
				while (lll) {
					printf("�Ј��ԍ�����́F");
					scanf_s("%d", &mmm);

					//����
					if (syainExistence(mmm) == 0) {
						lll = 0;
						printf("%s", syainnumSearch(mmm));
						break;
					}
					else if (syainExistence(mmm) == 1) {
						printf("�o�^������܂���B\n");
						printf("���j���[�֖߂�܂����H �߂�ꍇ��y�A������ꍇ��n����͂��Ă��������B\n");
						printf("y��n����́F");
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
					printf("��������́F");
					scanf_s("%s", ppp, 256);

					//����
					if (nameExistence(ppp) == 0) {
						ooo = 0;
						printf("%s", nameSearch(ppp));

						printf("�������������ɂ��܂����H ����ꍇ��y�A���Ȃ��ꍇ��n����͂��Ă��������B\n");
						printf("y��n����́F");
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
						printf("�o�^������܂���B\n");
						printf("���j���[�֖߂�܂����H �߂�ꍇ��y�A������ꍇ��n����͂��Ă��������B\n");
						printf("y��n����́F");
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
					printf("�����R�[�h����́F");
					scanf_s("%d", &rrr);

					//����
					if (busyocodeExistence(rrr) == 0) {
						qqq = 0;

						printf("����: %d.", rrr);
						printf("%s�ł��B\n", busyocodeSearch(rrr));

						break;
					}
					else if (busyocodeExistence(rrr) == 1) {
						printf("�o�^������܂���B\n");
						printf("���j���[�֖߂�܂����H �߂�ꍇ��y�A������ꍇ��n����͂��Ă��������B\n");
						printf("y��n����́F");
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
			printf("�V����������o�^���܂��B\n");

			ww = 1;
			while (ww) {
				printf("�����R�[�h����́F");
				scanf_s("%d", &ss);

				//����
				if (busyocodeExistence(ss) == 0) {
					printf("�����R�[�h %d �͓o�^�ςł��B\n", ss);
					printf("���o�^�ϕ����ꗗ��\n%s", busyoList());
				}
				else if (busyocodeExistence(ss) == 1) {
					ww = 0;
					break;
				}
			}

			bbb = 1;
			while (bbb) {
				printf("����������́F");
				scanf_s("%s", uu, (unsigned)_countof(uu)); //unsigned�͕����Ȃ������^�̃L�[���[�h�Acountof�͔z��̗v�f�����擾���邽�߂̃}�N��

				//����
				if (busyonameExistence(uu) == 0) {
					printf("������ %s �͓o�^�ςł��B\n", uu);
				}
				else if (busyonameExistence(uu) == 1) {
					bbb = 0;

				}
			}

			d = fopen_s(&tt, busyoTxt, "a"); //�ǉ���������
			if (d != 0) {
				printf("�t�@�C�����J���܂���B\n");
				return 10;
			}

			fprintf(tt, "%d.", ss); //�����R�[�h
			fprintf(tt, "%s\n", uu); //������

			fclose(tt);

			busyoChange(ss);

			printf("�����R�[�h: %d , �������F %s �o�^���܂����B\n", ss, uu);

			break;


		case 6:
			printf("�����̓o�^���폜���܂��B\n");

			hhh = 1;
			while (hhh) {
				printf("�����R�[�h����́F");
				scanf_s("%d", &ggg);

				//����
				if (busyocodeExistence(ggg) == 0) {
					hhh = 0;

					printf("�폜���܂����H �폜����ꍇ��y�A�폜���Ȃ��ꍇ��n����͂��Ă��������B\n");

					iii = 1;
					while (iii) {
						printf("y��n����́F");
						scanf_s(" %c", &jjj, 1);

						if (jjj == 'y') {

							busyocodeDeletion(ggg);

							printf("�폜���܂����B\n");
							iii = 0;
							break;
						}
						else if (jjj == 'n') {
							printf("�L�����Z�����܂����B\n");
							iii = 0;
							break;
						}
						else {
							printf("������x���͂��Ă��������B\n");
						}
					}
					hhh = 0;
					break;
				}
				else if (busyocodeExistence(ggg) == 1) {
					printf("�o�^������܂���B\n");
					printf("���j���[�֖߂�܂����H �߂�ꍇ��y�A������ꍇ��n����͂��Ă��������B\n");
					printf("y��n����́F");
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
			printf("���o�^�ώЈ��ꗗ��\n�Ј��ԍ�   ����      ����\n%s", syainList(syainsan, busyodesu, syainnum));
			break;

		case 8:
			printf("���o�^�ϕ����ꗗ��\n�����R�[�h  ������\n%s", busyoList());
			break;

		case 9:
			printf("�I�����܂����B\n");

			h = 0;
			break;

		default:
			printf("������x���͂��Ă��������B\n");

			break;
		}
	}
}


//1.�Ј��̃f�[�^�����݂���E���Ȃ��֐�

//�Ј��ԍ� ����
int syainExistence(int d) {

	int z; //��
	syain syainsan[256];
	busyocode busyodesu[256];

	for (z = 0; z < syainSplit(syainsan, busyodesu); z++) {
		if (d == syainsan[z].syainNum) {
			return 0;
		}
	}
	return 1;
}


//���� ����
int nameExistence(char* d) {

	int z; //��
	syain syainsan[256];
	busyocode busyodesu[256];

	for (z = 0; z < syainSplit(syainsan, busyodesu); z++) {
		if (strncmp(syainsan[z].Name, d, strlen(d)) == 0) {
			return 0;
		}
	}

	return 1;
}

//2.�����R�[�h�����݂���E���Ȃ��֐�

//�����R�[�h ����
int busyocodeExistence(int aa) {

	int z; //��
	syain syainsan[256];
	busyocode busyodesu[256];

	for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
		if (aa == busyodesu[z].busyoCode2) {
			return 0;
		}
	}
	return 1;
}


//������ ����
int busyonameExistence(char* aa) {

	int z; //��
	syain syainsan[256];
	busyocode busyodesu[256];

	for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
		if (strcmp(aa, busyodesu[z].busyoName) == 0) { //�����񂪓�������0��Ԃ�
			return 0;
		}
	}
	return 1;
}
//
//
//3.�ꗗ�֐�

// �Ј� �ꗗ
char* syainList(syain syainsan[256], busyocode busyodesu[256], int syainnum) { //�Ј��\���́A�����\���́A�Ј��l��+1

	int z; //��
	static char y[256]; //1�l
	static char n[1000]; //�S��

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
// �����R�[�h �ꗗ

char* busyoList() {

	int z; //��
	syain syainsan[256];
	busyocode busyodesu[256];
	static char y[256]; //1��
	static char n[1000]; //�S��

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
//	FILE* bb; //�t�@�C��
//	char u[256]; //�ۑ�����z��
//	static char y[256]; //"�����R�[�h�����݂��܂���B"������
//	static char ll[256]; //�o�^����Ă��镔���R�[�h�S�������
//	size_t v;
//	errno_t a;
//	static char k[256];
//
//	a = fopen_s(&bb, busyoTxt, "a"); //�ǂݍ���
//	if (a != 0) {
//		strcpy_s(k, 256, "�t�@�C�����J���܂���B\n");
//		return k;
//	}
//
//	fclose(bb);
//
//	a = fopen_s(&bb, busyoTxt, "r"); //�ǂݍ���
//	if (a != 0) {
//		strcpy_s(k, 256, "�t�@�C�����J���܂���B\n");
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
//		strcpy_s(y, 256, "�����R�[�h�����݂��܂���B\n");
//
//		return y;
//	}
//	else {
//		strcpy_s(ll, 256, u);
//
//		return ll;
//	}
//}


//4.�폜�֐�

//�Ј��ԍ� �폜
int syainnumDeletion(int z) {

	FILE* b; //�t�@�C��
	errno_t a;
	int h; //��
	syain syainsan[256];
	busyocode busyodesu[256];

	a = fopen_s(&b, syainTxt, "w+"); //�X�V��������
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
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

//�����R�[�h �폜
int busyocodeDeletion(int z) {

	FILE* b; //�t�@�C��
	errno_t a;
	int h; //��
	syain syainsan[256];
	busyocode busyodesu[256];

	a = fopen_s(&b, busyoTxt, "w+"); //�X�V��������
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
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

//5.�����֐�

//�Ј��ԍ����猟��
char* syainnumSearch(int b) {

	int zz; //��
	int z; //��
	static char y[256]; //����
	static char n[256]; //�ꕔ
	static char p[256]; //�G���[
	syain syainsan[256];
	busyocode busyodesu[256];

	memset(&y[0], '\0', sizeof(y));
	memset(&n[0], '\0', sizeof(n));
	memset(&p[0], '\0', sizeof(p));

	for (zz = 0; zz < syainSplit(syainsan, busyodesu); zz++) {
		//�Ј��ԍ�b�ƎЈ��ԍ���v���邩
		if (b == syainsan[zz].syainNum) {

			sprintf_s(y, sizeof(y), "�Ј��ԍ�: %d , ����: %s , ����: %d", syainsan[zz].syainNum, syainsan[zz].Name, syainsan[zz].busyoCode);

		}
	}

	for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
		//�����R�[�h�ƕ����̃R�[�h��v���邩
		if (zz > 0 && syainsan[zz - 1].busyoCode == busyodesu[z].busyoCode2) { //zz++ ����Ă��� 1�������� -1����Azz ��0�̏ꍇ�ɂ͂��̏��������s���Ȃ��悤�� zz > 0

			sprintf_s(n, sizeof(n), ".%s �ł��B\n", busyodesu[z].busyoName);

			strcat_s(y, sizeof(y), n);

			return y;
		}
	}

	strcpy_s(p, sizeof(p), "�G���[���������܂����B\n");
	return p;
}


//�������猟��
char* nameSearch(char* b) {

	int zz; //��
	int z; //��
	static char y[256]; //����
	static char n[256]; //�ꕔ
	syain syainsan[256];
	busyocode busyodesu[256];

	memset(&y[0], '\0', sizeof(y));
	memset(&n[0], '\0', sizeof(n));

	for (zz = 0; zz < syainSplit(syainsan, busyodesu); zz++) {
		//����b�Ǝ�����v���邩
		if (strncmp(syainsan[zz].Name, b, strlen(b)) == 0) {

			sprintf_s(y, sizeof(y), "�Ј��ԍ�: %d , ����: %s , ����: %d", syainsan[zz].syainNum, syainsan[zz].Name, syainsan[zz].busyoCode);

			strncat_s(n, sizeof(n), y, sizeof(n) - strlen(n) - 1);

			for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
				if (syainsan[zz].busyoCode == busyodesu[z].busyoCode2) {

					sprintf_s(y, sizeof(y), ".%s �ł��B\n", busyodesu[z].busyoName);

					strncat_s(n, sizeof(n), y, sizeof(n) - strlen(n) - 1);

				}
			}
		}
	}

	return n;
}


//�������猟��
char* nameSearchOrder(char* b) {

	int zz; //��
	int z; //��
	static char y[256]; //�ꕔ
	static char n[256]; //����
	syain syainsan[256];
	busyocode busyodesu[256];

	syainSplit(syainsan, busyodesu);

	nameSort(syainsan, syainSplit(syainsan, busyodesu));

	memset(&y[0], '\0', sizeof(y));
	memset(&n[0], '\0', sizeof(n));

	for (zz = 0; zz < syainSplit(syainsan, busyodesu); zz++) {
		//����b�Ǝ�����v���邩
		if (strncmp(syainsan[zz].Name, b, strlen(b)) == 0) {

			sprintf_s(y, sizeof(y), "�Ј��ԍ�: %d , ����: %s , ����: %d", syainsan[zz].syainNum, syainsan[zz].Name, syainsan[zz].busyoCode);

			strncat_s(n, sizeof(n), y, sizeof(n) - strlen(n) - 1);

			for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
				if (syainsan[zz].busyoCode == busyodesu[z].busyoCode2) {

					sprintf_s(y, sizeof(y), ".%s �ł��B\n", busyodesu[z].busyoName);

					strncat_s(n, sizeof(n), y, sizeof(n) - strlen(n) - 1);

				}
			}
		}
	}

	return n;
}


//�����R�[�h����S��
char* busyocodeSearch(int b) {

	int zz; //��
	int z; //��
	static char y[256]; //�ꕔ
	static char m[256]; //�ꕔ
	static char n[256]; //����
	static char p[256]; //�G���[
	syain syainsan[256];
	busyocode busyodesu[256];

	memset(&y[0], '\0', sizeof(y));
	memset(&m[0], '\0', sizeof(m));
	memset(&n[0], '\0', sizeof(n));
	memset(&p[0], '\0', sizeof(p));

	//�����R�[�hb�ƕ����R�[�h��v���邩
	for (zz = 0; zz < syainSplit(syainsan, busyodesu); zz++) {
		if (b == syainsan[zz].busyoCode) {

			sprintf_s(y, sizeof(y), "�Ј��ԍ�: %d , ����: %s\n", syainsan[zz].syainNum, syainsan[zz].Name); //sprintf_s�͕ϐ��𕶎���ɕϊ����đ}��

			strcat_s(m, sizeof(m), y);

		}
	}

	//�Ј��̕����R�[�h�ƕ����̕����R�[�h��v���邩
	for (z = 0; z < busyoSplit(syainsan, busyodesu); z++) {
		if (b == busyodesu[z].busyoCode2) {

			sprintf_s(n, sizeof(n), "%s �֓o�^����Ă���̂�\n", busyodesu[z].busyoName);

			strcat_s(n, sizeof(n), m);

			return n;
		}
	}

	strcpy_s(p, sizeof(p), "�G���[���������܂����B\n");
	return p;
}


//6.�Ј���� �ύX
int syainChange(int z, char* c, int d) {

	FILE* b; //�t�@�C��
	errno_t a;
	int h; //��
	syain syainsan[256];
	busyocode busyodesu[256];
	int e;

	e = syainSplit(syainsan, busyodesu);

	syainSort(syainsan, e);

	//��v������ύX�������̂��������ށA�Y�����Ȃ����̂͂��̂܂ܑS�ď�������
	a = fopen_s(&b, syainTxt, "w+"); //��������
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
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


//���� �ύX
int busyoChange(int z) {

	FILE* b; //�t�@�C��
	errno_t a;
	int h; //��
	syain syainsan[256];
	busyocode busyodesu[256];
	int e;

	e = busyoSplit(syainsan, busyodesu);

	busyoSort(busyodesu, e);

	a = fopen_s(&b, busyoTxt, "w+"); //�X�V��������
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
		return 10;
	}

	for (h = 0; h < e; h++) {

		fprintf(b, "%d.%s\n", busyodesu[h].busyoCode2, busyodesu[h].busyoName);
	}

	fclose(b);

	return 0;
}


//7.������ �o��
char* busyoName(int aa, int syainnum, busyocode busyodesu[256]) { //�Ј��l���\���̂̕����R�[�h�A�Ј��l��+1�A�����\����

	int z; //��
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
	strcpy_s(n, 256, "�G���[���������܂����B");
	return n;
}


//8.���בւ��֐� �o�u���\�[�g

//�Ј��ԍ� ���בւ�
void syainSort(syain a[], int b) { //�\���́A�\���̂̉��Ԗ�

	int c; //����
	int d; //����
	syain e; //�\���̋�

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


//���� ���בւ�
void nameSort(syain a[], int b) { //�\���́A�\���̂̉��Ԗ�

	int c; //����
	int d; //����
	syain e; //�\���̋�

	for (c = 0; c < b - 1; c++) {
		for (d = 0; d < b - 1; d++) {
			if (strcmp(a[d].Name, a[d + 1].Name) > 0) { //strcmp�͕����񂪓��������A�܂��͂ǂ��炪�������Ő悩���r
				e = a[d];
				a[d] = a[d + 1];
				a[d + 1] = e;
			}
		}
	}
}


//�����R�[�h ���בւ�
void busyoSort(busyocode a[], int b) { //�\���́A�\���̂̉��Ԗ�

	int c; //����
	int d; //����
	busyocode e; //�\���̋�

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


//���בւ��֐� �I���\�[�g

//�Ј��ԍ� ���בւ�
//void syainSort(syain a[], int b) { //�\���́A�\���̂̉��Ԗ�
//
//	int c; //����
//	int d; //����
//	int f; //�ŏ�
//	syain e; //�\���̋�
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


//9.�����֐�

//���� �Ј�
int syainSplit(syain syainsan[256], busyocode busyodesu[256]) {

	FILE* txt; //�t�@�C��
	errno_t a;
	static char nop[256]; //�t�@�C�����J���܂���B
	char ichigyou[256]; //1�s�ۑ�����z��
	int d; //��
	char bangou[256]; //1�����������z��
	int suji; //�����ɂ������̂�����@
	int e; //��
	char simei[256]; //1�����������z��
	char busyobangou[256]; //1�����������z��
	int i; //��
	int suji2; //�����ɂ������̂�����
	int syainnum;

	char ichigyou2[256]; //1�s�ۑ�����z��
	char bangou2[256];
	char busyomei[256];
	int busyonum;

	syainnum = 0;
	busyonum = 0;

	a = fopen_s(&txt, syainTxt, "a"); //�ǂݍ���
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
		return 10;
	}

	fclose(txt);

	a = fopen_s(&txt, syainTxt, "r"); //�ǂݍ���
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
		return 10;
	}

	while (fgets(ichigyou, 256, txt) != NULL) {  //(1�s�ۑ�����z��A�z��̃T�C�Y�A�ǂ̃t�@�C��)

		memset(&bangou[0], '\0', sizeof(bangou));
		memset(&simei[0], '\0', sizeof(simei));
		memset(&busyobangou[0], '\0', sizeof(busyobangou));

		//�Ј��ԍ�
		for (d = 0; ichigyou[d] != ','; d++) {
			bangou[d] = ichigyou[d];
		}

		suji = atoi(bangou);
		syainsan[syainnum].syainNum = suji;

		//����
		for (d = d + 1, e = 0; ichigyou[d] != ','; d++, e++) {
			simei[e] = ichigyou[d];
		}

		strcpy_s(syainsan[syainnum].Name, 256, &simei[0]);


		//�����R�[�h
		for (d = d + 1, i = 0; ichigyou[d] != '\0' && ichigyou[d] != '\n'; d++, i++) {
			busyobangou[i] = ichigyou[d];
		}

		suji2 = atoi(busyobangou);
		syainsan[syainnum].busyoCode = suji2;

		syainnum++;

	}

	fclose(txt);


	a = fopen_s(&txt, busyoTxt, "a"); //�ǂݍ���
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
		return 10;
	}

	fclose(txt);

	a = fopen_s(&txt, busyoTxt, "r"); //�ǂݍ���
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
		return 10;
	}

	while (fgets(ichigyou2, 256, txt) != NULL) {  //(1�s�ۑ�����z��A�z��̃T�C�Y�A�ǂ̃t�@�C��)

		memset(&bangou2[0], '\0', sizeof(bangou2));
		memset(&busyomei[0], '\0', sizeof(busyomei));

		//�����R�[�h
		for (d = 0; ichigyou2[d] != '.'; d++) {
			bangou2[d] = ichigyou2[d];
		}

		suji = atoi(bangou2);
		busyodesu[busyonum].busyoCode2 = suji;

		//������
		for (d = d + 1, e = 0; ichigyou2[d] != '\0' && ichigyou2[d] != '\n'; d++, e++) {
			busyomei[e] = ichigyou2[d];
		}

		strcpy_s(busyodesu[busyonum].busyoName, 256, &busyomei[0]);

		busyonum++;

	}

	fclose(txt);

	return syainnum;
}


//���� ����
int busyoSplit(syain syainsan[256], busyocode busyodesu[256]) {

	FILE* txt; //�t�@�C��
	errno_t a;
	static char nop[256]; //�t�@�C�����J���܂���B
	char ichigyou[256]; //1�s�ۑ�����z��
	int d; //��
	char bangou[256]; //1�����������z��
	int suji; //�����ɂ������̂�����@
	int e; //��
	char simei[256]; //1�����������z��
	char busyobangou[256]; //1�����������z��
	int i; //��
	int suji2; //�����ɂ������̂�����
	int syainnum;

	char ichigyou2[256]; //1�s�ۑ�����z��
	char bangou2[256];
	char busyomei[256];
	int busyonum;

	syainnum = 0;
	busyonum = 0;

	a = fopen_s(&txt, syainTxt, "a"); //�ǂݍ���
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
		return 10;
	}

	fclose(txt);

	a = fopen_s(&txt, syainTxt, "r"); //�ǂݍ���
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
		return 10;
	}

	while (fgets(ichigyou, 256, txt) != NULL) {  //(1�s�ۑ�����z��A�z��̃T�C�Y�A�ǂ̃t�@�C��)

		memset(&bangou[0], '\0', sizeof(bangou));
		memset(&simei[0], '\0', sizeof(simei));
		memset(&busyobangou[0], '\0', sizeof(busyobangou));

		//�Ј��ԍ�
		for (d = 0; ichigyou[d] != ','; d++) {
			bangou[d] = ichigyou[d];
		}

		suji = atoi(bangou);
		syainsan[syainnum].syainNum = suji;

		//����
		for (d = d + 1, e = 0; ichigyou[d] != ','; d++, e++) {
			simei[e] = ichigyou[d];
		}

		strcpy_s(syainsan[syainnum].Name, 256, &simei[0]);


		//�����R�[�h
		for (d = d + 1, i = 0; ichigyou[d] != '\0' && ichigyou[d] != '\n'; d++, i++) {
			busyobangou[i] = ichigyou[d];
		}

		suji2 = atoi(busyobangou);
		syainsan[syainnum].busyoCode = suji2;

		syainnum++;

	}

	fclose(txt);


	a = fopen_s(&txt, busyoTxt, "a"); //�ǂݍ���
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
		return 10;
	}

	fclose(txt);

	a = fopen_s(&txt, busyoTxt, "r"); //�ǂݍ���
	if (a != 0) {
		printf("�t�@�C�����J���܂���B\n");
		return 10;
	}

	while (fgets(ichigyou2, 256, txt) != NULL) {  //(1�s�ۑ�����z��A�z��̃T�C�Y�A�ǂ̃t�@�C��)

		memset(&bangou2[0], '\0', sizeof(bangou2));
		memset(&busyomei[0], '\0', sizeof(busyomei));

		//�����R�[�h
		for (d = 0; ichigyou2[d] != '.'; d++) {
			bangou2[d] = ichigyou2[d];
		}

		suji = atoi(bangou2);
		busyodesu[busyonum].busyoCode2 = suji;

		//������
		for (d = d + 1, e = 0; ichigyou2[d] != '\0' && ichigyou2[d] != '\n'; d++, e++) {
			busyomei[e] = ichigyou2[d];
		}

		strcpy_s(busyodesu[busyonum].busyoName, 256, &busyomei[0]);

		busyonum++;

	}

	fclose(txt);

	return busyonum;
}