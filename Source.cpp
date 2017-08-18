#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <time.h>
using namespace std;

int max(int a, int b)
{
	return (a > b ? a : b);
}

bool compare(int a, int b)
{
	return a > b;
}

int cmp(const void *a, const void *b)
{
	return *(int*)a < *(int*)b;
}

void Pat1001()
{
	int n, count = 0;
	scanf("%d", &n);
	while (n != 1)
	{
		if (n % 2){ n = (3 * n + 1) / 2; ++count; }
		else{ n = n / 2; ++count; }
	}
	printf("%d\n", count);
}

void Pat1002()
{
	char str[10][5] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
	char num[102];
	scanf("%s", num);
	int i = 0, sum = 0;
	while (num[i] != '\0'){ sum += num[i] - '0'; ++i; }
	int a[3];
	a[0] = a[1] = a[2] = -1;
	i = 2;
	while (sum / 10)
	{
		a[i--] = sum % 10;
		sum = sum / 10;
	}
	a[i] = sum;
	for (i; i < 2; ++i)printf("%s ", str[a[i]]);
	printf("%s\n", str[a[2]]);
}

//Ū�����Ŀ��˼�������ֹ���
void Pat1003()
{
	int a, b, c, pos, n;
	char str[101];
	scanf("%d", &n);
	getchar();
	for (int i = 0; i<n; ++i)
	{
		a = b = c = pos = 0;
		int j = 0, p = 0, t = 0, es = 0;
		while ((str[j] = getchar()) != '\n')
		{
			if (str[j] != 'P' && str[j] != 'A' && str[j] != 'T')++es;
			if (str[j] == 'A' && pos == 0)++a;
			if (str[j] == 'A' && pos == 1)++b;
			if (str[j] == 'A' && pos == 2)++c;
			if (str[j] == 'P'){ pos = 1; ++p; }
			if (str[j] == 'T'&&pos == 1){ pos = 2; ++t; }
			++j;
		}
		if (pos == 2 && b && p == 1 && t == 1 && !es)
		{
			if (((b - 1)*a + a == c) || (a == c&&b == 1))printf("YES\n");
			else printf("NO\n");
		}
		else printf("NO\n");
	}
}

void Pat1004()
{
	typedef struct stu{
		char name[11];
		char id[11];
		int score;
	}stu;
	int n;
	stu max, min;
	scanf("%d", &n);
	scanf("%s %s %d", max.name, max.id, &max.score);
	strcpy(min.name, max.name);
	strcpy(min.id, max.id);
	min.score = max.score;
	--n;
	while (n--)
	{
		stu tmp;
		scanf("%s %s %d", tmp.name, tmp.id, &tmp.score);
		if (tmp.score>max.score){ strcpy(max.name, tmp.name); strcpy(max.id, tmp.id); max.score = tmp.score; }
		else if (tmp.score<min.score){ strcpy(min.name, tmp.name); strcpy(min.id, tmp.id); min.score = tmp.score; }
	}
	printf("%s %s\n%s %s\n", max.name, max.id, min.name, min.id);
}

//������
void Pat1005()
{
	int a[15000], num[100];
	for (int i = 0; i<150; ++i)a[i] = 0;
	int K, count = 0;
	scanf("%d", &K);
	for (int i = 0; i<K; ++i)
	{
		scanf("%d", &num[i]);
	}
	qsort(num, K, sizeof(int), cmp);
	for (int i = 0; i<K; ++i)
	{
		int tmp = num[i];
		if (tmp % 2)tmp = (3 * tmp + 1) / 2; else tmp = tmp / 2;
		while (a[tmp] != 1)
		{
			a[tmp] = 1;
			if (tmp % 2)tmp = (3 * tmp + 1) / 2; else tmp = tmp / 2;
		}
	}
	for (int i = 0; i < K; ++i)
	{
		if (!a[num[i]])++count;
	}
	for (int i = 0; i<K; ++i)
	{
		if (!a[num[i]])
		{
			--count; if (count)printf("%d ", num[i]); else printf("%d", num[i]);
		};
	}
	printf("\n");
}

void Pat1006()
{
	char str[4];
	scanf("%s", str);
	int length = strlen(str);
	if (length == 3)
	{
		int i = str[0] - '0'; while (i--)printf("B");
		i = str[1] - '0'; while (i--)printf("S");
		i = str[2] - '0'; int j = 0; while (j<i)printf("%d", j + 1);
	}
	if (length == 2)
	{
		int i = str[0] - '0'; while (i--)printf("S");
		i = str[1] - '0'; int j = 0; while (j<i)printf("%d", j + 1);
	}
	if (length == 1)
	{
		int i = str[0] - '0'; int j = 0; while (j<i)printf("%d", j + 1);
	}
	printf("\n");
}

void Pat1007()
{
	int N, prev, count, i, j;
	prev = 2;
	count = 0;
	scanf("%d", &N);
	for (i = 2; i <= N; ++i)
	{
		if (i % 2 == 0 && i != 2)continue;
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i % j == 0)
				break;
		}
		if (j>sqrt(i))
		{
			if (i - prev == 2)
				count += 1;
			prev = i;
		}
	}
	printf("%d\n", count);
}

void Pat1008()
{
	int N, M;
	int a[101];
	scanf("%d %d", &N, &M);
	int i = 1;
	while (i <= N)
	{
		if (M > N)
		{
			M = M%N;
		}
		if (i <= N - M)
			scanf("%d", &a[i + M]);
		else
			scanf("%d", &a[M - N + i]);
		++i;
	}
	i = 1;
	while (i <= N)
	{
		if (i == N)
			printf("%d", a[i]);
		else
			printf("%d ", a[i]);
		++i;
	}
}

void Pat1009()
{
	char inStr[100];
	char outStr[100][100];
	gets(inStr);
	int i = 0;
	int j = 0;
	int k = 0;
	while (inStr[i] != '\0')
	{
		if (inStr[i] != ' ')
		{
			outStr[j][k++] = inStr[i];
		}
		else
		{
			outStr[j][k] = '\0';
			k = 0;
			j += 1;
		}
		++i;
	}
	outStr[j][k] = '\0';
	while (j >= 0)
	{
		if (j != 0)
		{
			printf("%s", outStr[j]);
			printf(" ");
		}
		else
		{
			printf("%s", outStr[j]);
		}
		--j;
	}
}

//
//
//
void Pat1010()
{
	int a, b;
	int flag = 1, count = 0;
	while (scanf("%d %d", &a, &b) != EOF)
	{
		++count;
		if (b != 0)
		{
			if (flag == 1)
			{
				printf("%d %d", a*b, b - 1);
				flag = 0;
			}
			else
			{
				printf(" %d %d", a*b, b - 1);
			}
		}
		else
			if (count == 1)
				printf("0 0\n");
	}
}

void Pat1011()
{
	int T;
	long int a, b, c;
	int i = 1;
	scanf("%d", &T);
	while (i <= T)
	{
		scanf("%ld %ld %ld", &a, &b, &c);
		if (a + b > c)
		{
			printf("Case #%d: true\n", i);
		}
		else
		{
			printf("Case #%d: false\n", i);
		}
		++i;
	}
}

void Pat1012()
{
	int N, count[5], a1Sum = 0, a4Sum = 0, max = 0;
	for (int i = 0; i<5; ++i)count[i] = 0;
	scanf("%d", &N);
	while (N--)
	{
		int tmp;
		scanf("%d", &tmp);
		switch (tmp % 5)
		{
		case 0:if (!(tmp % 2))count[0] += tmp; break;
		case 1:++count[1]; if (count[1] % 2)a1Sum += tmp; else a1Sum -= tmp; break;
		case 2:++count[2]; break;
		case 3:a4Sum += tmp; ++count[3]; break;
		case 4:++count[4]; if (tmp>max)max = tmp; break;
		default:break;
		}
	}
	for (int i = 0; i<5; ++i)
	{
		if (i == 0){ if (!count[i])printf("N "); else printf("%d ", count[i]); }
		if (i == 1){ if (!count[i])printf("N "); else printf("%d ", a1Sum); }
		if (i == 2){ if (!count[i])printf("N "); else printf("%d ", count[i]); }
		if (i == 3){ if (!count[i])printf("N "); else printf("%.1lf ", (double)a4Sum / count[i]); }
		if (i == 4){ if (!count[i])printf("N"); else printf("%d", max); }
	}
}

void Pat1013()
{
	int M, N, count = 0, sumCount = 0, i = 2, j = 2, isSuShu = 1;
	scanf("%d %d", &M, &N);

	while (1)
	{
		for (j = 2; j <= sqrt(i); ++j)
		{
			if (i % 2 == 0 && i != 2){ isSuShu = 0; break; }
			if (i%j == 0){ isSuShu = 0; break; }
		}
		if (j > sqrt(i))isSuShu = 1;
		if (isSuShu)
		{
			count += 1;
			if (count >= M&&count <= N)
			{
				sumCount += 1;
				if (sumCount % 10 == 0)
				{
					printf("%d\n", i);
				}
				else if (sumCount == N - M + 1)
				{
					printf("%d", i);
				}
				else
					printf("%d ", i);
			}
			else if (count > N)
				break;
		}
		++i;
	}
}

void Pat1014()
{
	char str[4][70];
	int i = 0;
	int j = 0;
	char day, hh, ss;
	bool isFindDay = false;
	bool isFindHh = false;
	bool isFindSs = false;
	for (int i = 0; i < 4; ++i)
	{
		gets(str[i]);
	}
	i = 0;
	while (str[0][i] != '\0')
	{
		if (str[0][i] >= 65 && str[0][i] <= 71)
		{
			day = str[0][i];
			for (j = 0; str[1][j] != '\0'; ++j)
			{
				if (str[1][j] == day)
				{
					isFindDay = true;
					break;
				}
			}
		}
		if (isFindDay)
			break;
		++i;
	}
	++i;
	++j;
	while (str[0][i] != '\0')
	{
		if (str[0][i] >= 65 && str[0][i] <= 78)
		{
			hh = str[0][i];
			for (j; str[1][j] != '\0'; ++j)
			{
				if (str[1][j] == hh)
				{
					isFindHh = true;
					break;
				}
			}
		}
		if (isFindHh)
			break;
		++i;
	}
	i = 0;
	j = 0;
	while (str[2][i] != '\0')
	{
		if ((str[2][i] >= 65 && str[2][i] <= 90) ||
			(str[2][i] >= 97 && str[2][i] <= 122))
		{
			ss = str[2][i];
			for (j = 0; str[3][j] != '\0'; ++j)
			{
				if (str[3][j] == ss)
				{
					isFindSs = true;
					break;
				}
			}
		}
		if (isFindSs)
			break;
		++i;
	}
	switch (day)
	{
	case 65:printf("MON "); break;
	case 66:printf("TUE "); break;
	case 67:printf("WED "); break;
	case 68:printf("THU "); break;
	case 69:printf("FRI "); break;
	case 70:printf("SAT "); break;
	case 71:printf("SUN "); break;
	default:break;
	}
	int a[15] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	int posHh = hh - 65;
	if (j > 9)
		printf("%d:%d\n", a[posHh], j);
	else
		printf("%d:0%d\n", a[posHh], j);
}
//qsort
typedef struct stu{
	int id;
	int deScore;
	int caiScore;
	int sumScore;
	int type;
}stu;

int cmpStu(const void *a, const void *b)
{
	struct stu *c = (stu*)a;
	struct stu *d = (stu*)b;
	if ((*c).type == (*d).type)
		if ((*c).sumScore == (*d).sumScore)
			if ((*c).deScore == (*d).deScore)
				return (*c).id - (*d).id;
			else
				return (*d).deScore - (*c).deScore;
		else
			return (*d).sumScore - (*c).sumScore;
	else
		return (*c).type - (*d).type;
}

void Pat1015()
{
	int N, L, H, count = 0;
	scanf("%d %d %d", &N, &L, &H);
	stu *stuNum = (stu*)malloc(N*sizeof(stu));
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %d", &stuNum[i].id, &stuNum[i].deScore, &stuNum[i].caiScore);
		stuNum[i].sumScore = stuNum[i].deScore + stuNum[i].caiScore;
		if (stuNum[i].deScore >= H&&stuNum[i].caiScore >= H)
			stuNum[i].type = 1;
		if (stuNum[i].deScore >= H&&stuNum[i].caiScore >= L&&stuNum[i].caiScore < H)
			stuNum[i].type = 2;
		if (stuNum[i].deScore >= L&&stuNum[i].caiScore >= L&&stuNum[i].deScore >= stuNum[i].caiScore
			&&stuNum[i].deScore < H&&stuNum[i].caiScore < H)
			stuNum[i].type = 3;
		if (stuNum[i].deScore >= L&&stuNum[i].caiScore >= L&&stuNum[i].deScore < stuNum[i].caiScore
			&&stuNum[i].deScore < H)
			stuNum[i].type = 4;
		if (stuNum[i].deScore < L || stuNum[i].caiScore < L)
			stuNum[i].type = 5;
		if (stuNum[i].type == 1 || stuNum[i].type == 2 || stuNum[i].type == 3 || stuNum[i].type == 4)++count;
	}
	qsort(stuNum, N, sizeof(stu), cmpStu);
	printf("%d\n", count);
	for (int i = 0; i < N; ++i)
	{
		if (stuNum[i].type == 5)
			break;
		printf("%d %d %d\n", stuNum[i].id, stuNum[i].deScore, stuNum[i].caiScore);
	}
}

void Pat1016()
{
	char A[15], B[15];
	long int DA, DB;
	long int i, DANum, DBNum;
	long int sum = 0;
	i = 0;
	DANum = 0;
	DBNum = 0;
	scanf("%s %d %s %d", A, &DA, B, &DB);
	while (A[i] != '\0')
	{
		int a = A[i] - '0';
		if (a == DA)
			DANum += 1;
		++i;
	}
	i = 0;
	while (B[i] != '\0')
	{
		int a = B[i] - '0';
		if (a == DB)
			DBNum += 1;
		++i;
	}
	while (DANum)
	{
		int a = DA;
		for (int i = 1; i < DANum; ++i)
		{
			a = a * 10;
		}
		sum += a;
		--DANum;
	}
	while (DBNum)
	{
		int a = DB;
		for (int i = 1; i < DBNum; ++i)
		{
			a = a * 10;
		}
		sum += a;
		--DBNum;
	}
	printf("%ld\n", sum);
}
//��һ��ֻ��һλ���ֵĲ��Ե�
void Pat1017()
{
	char A[1001];
	int Q[1000], B = 0, R = 0, i = 0;
	scanf("%s %d", A, &B);
	for (i = 0; A[i] != '\0'; ++i)
	{
		int tmp = R * 10 + A[i] - '0';
		Q[i] = tmp / B;
		R = tmp%B;
	}
	for (int j = 0; j < i; ++j){ if (j == 0 && Q[j] == 0 && i != 1)continue; printf("%d", Q[j]); }
	putchar(' ');
	printf("%d\n", R);
}
//
//�Ż�
//
void Pat1018()
{
	int n;
	int countCofJia, countJofJia, countBofJia, countCofYi, countJofYi, countBofYi, countWin, countLose, maxJia, maxYi;
	countCofJia = countJofJia = countBofJia = countCofYi = countJofYi = countBofYi = countWin = countLose = maxJia = maxYi = 0;
	char a[2], b[2];
	scanf("%d", &n);
	int i = n;
	while (i)
	{
		scanf("%s %s", a, b);
		if (a[0] == 'C'&&b[0] == 'J')
		{
			countWin += 1;
			countCofJia += 1;
		}
		if (a[0] == 'J'&&b[0] == 'B')
		{
			countWin += 1;
			countJofJia += 1;
		}
		if (a[0] == 'B'&&b[0] == 'C')
		{
			countWin += 1;
			countBofJia += 1;
		}
		if (a[0] == 'J'&&b[0] == 'C')
		{
			countLose += 1;
			countCofYi += 1;
		}
		if (a[0] == 'B'&&b[0] == 'J')
		{
			countLose += 1;
			countJofYi += 1;
		}
		if (a[0] == 'C'&&b[0] == 'B')
		{
			countLose += 1;
			countBofYi += 1;
		}
		--i;
	}
	maxJia = max(countJofJia, max(countCofJia, countBofJia));
	maxYi = max(countJofYi, max(countCofYi, countBofYi));
	printf("%d %d %d\n", countWin, n - countWin - countLose, countLose);
	printf("%d %d %d\n", countLose, n - countWin - countLose, countWin);
	if (maxJia == countBofJia)
		printf("B ");
	else if (maxJia == countCofJia)
		printf("C ");
	else
		printf("J ");

	if (maxYi == countBofYi)
		printf("B");
	else if (maxYi == countCofYi)
		printf("C");
	else
		printf("J");
}
//���ַ����ᳬʱ
void Pat1019()
{
	int num;
	int number[4];
	int a = 0, b = 0, c = 0;
	scanf("%s", &num);
	number[0] = num / 1000;
	number[1] = num / 100 % 10;
	number[2] = num / 10 % 10;
	number[3] = num % 10;
	while (1)
	{
		sort(number, number + 4, compare);
		a = number[0] * 1000 + number[1] * 100 + number[2] * 10 + number[3];
		b = number[3] * 1000 + number[2] * 100 + number[1] * 10 + number[0];
		c = a - b;
		if (c != 0)
		{
			if (c == 6174)
			{
				printf("%04d - %04d = %04d\n", a, b, c);
				break;
			}
			printf("%04d - %04d = %04d\n", a, b, c);
		}
		else
		{
			printf("%04d - %04d = %04d\n", a, b, c);
			break;
		}
		number[0] = c / 1000;
		number[1] = c / 100 % 10;
		number[2] = c / 10 % 10;
		number[3] = c % 10;
	}
}
//�ṹ������
//���۸ߵ�����
//
typedef struct good{
	float num;
	float sumPrice;
	float perPrice;
}good;
int cmpa(const void *a, const void *b)
{
	return (*(good*)a).perPrice<(*(good*)b).perPrice;
}
void Pat1020()
{
	good g[1000];
	int N, D;
	float gain = 0.0f;
	scanf("%d %d", &N, &D);
	for (int i = 0; i<N; ++i)scanf("%f", &g[i].num);
	for (int i = 0; i<N; ++i)
	{
		scanf("%f", &g[i].sumPrice);
		g[i].perPrice = g[i].sumPrice / g[i].num;
	}
	qsort(g, N, sizeof(good), cmpa);
	for (int i = 0; i<N; ++i)
	{
		if (D <= g[i].num)
		{
			gain += D*g[i].perPrice;
			break;
		}
		else
		{
			D = D - g[i].num;
			gain += g[i].sumPrice;
		}
	}
	printf("%.2f\n", gain);
}

void Pat1021()
{
	char str[1000];
	int a[10] = { 0 };
	scanf("%s", str);
	int len = strlen(str);
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == '0')
			a[str[i] - '0'] += 1;
		if (str[i] == '1')
			a[str[i] - '0'] += 1;
		if (str[i] == '2')
			a[str[i] - '0'] += 1;
		if (str[i] == '3')
			a[str[i] - '0'] += 1;
		if (str[i] == '4')
			a[str[i] - '0'] += 1;
		if (str[i] == '5')
			a[str[i] - '0'] += 1;
		if (str[i] == '6')
			a[str[i] - '0'] += 1;
		if (str[i] == '7')
			a[str[i] - '0'] += 1;
		if (str[i] == '8')
			a[str[i] - '0'] += 1;
		if (str[i] == '9')
			a[str[i] - '0'] += 1;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (a[i] != 0)
			printf("%d:%d\n", i, a[i]);
	}
}

void Pat1022()
{
	int A, B, D;
	scanf("%d %d %d", &A, &B, &D);
	int C = A + B;
	int a[10000];
	for (int j = 0; j < 10000; ++j)
		a[j] = -1;
	int i = 0;
	for (i;; ++i)
	{
		if (C / D == 0)
			break;
		a[i] = C % D;
		C = C / D;
	}
	a[i] = C % D;
	for (i; i >= 0; --i)
	{
		printf("%d", a[i]);
	}
}

void Pat1023()
{
	int a[10];
	char str[55];
	int pos = 1;
	for (int i = 0; i < 55; ++i)
		str[i] = '\0';
	for (int i = 0; i < 10; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < 10; ++i)
	{
		if (a[i] != 0)
		{
			str[0] = i + '0';
			--a[i];
			break;
		}
	}
	for (int i = 0; i < 10; ++i)
	{
		while (a[i]-- != 0)str[pos++] = i + '0';
	}
	printf("%s", str);
}

//���������Ե㳬ʱ
void Pat1024()
{
	char sym, A[10000];
	int i = 0;
	sym = getchar();
	while ((A[i++] = getchar()) != 'E');
	int e;
	scanf("%d", &e);
	i -= 3;
	if (sym == '-')putchar('-');
	if (e >= 0)
	{
		if (e <= i)
		{
			putchar(A[0]);
			int j = 1;
			while (e){ if (A[j] != '.'){ putchar(A[j++]); --e; } }
			while (A[j] != 'E')putchar(A[j++]);
		}
		else
		{
			int j = 0;
			while (A[j] != 'E'){ if (A[j] != '.')putchar(A[j]); ++j; }
			j = e - i;
			while (j--)putchar('0');
		}
	}
	else
	{
		int j = abs(e);
		putchar('0'); putchar('.'); --j;
		while (j--)putchar('0');
		++j;
		while (A[j] != 'E'){ if (A[j] != '.')putchar(A[j]); ++j; }
	}
}

void Pat1025()
{
	typedef struct listnode{
		int address;
		int data;
		int next;
	} listnode;
	vector<listnode> vin(100000);
	vector<listnode> vsort;
	vector<listnode> vout;
	int firstAddress, N, K;
	listnode tmp;
	scanf("%d %d %d", &firstAddress, &N, &K);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %d", &tmp.address, &tmp.data, &tmp.next);
		vin[tmp.address] = tmp;
	}
	vsort.push_back(vin[firstAddress]);
	int nextAddress = vin[firstAddress].next;
	while (nextAddress != -1)
	{
		vsort.push_back(vin[nextAddress]);
		nextAddress = vin[nextAddress].next;
	}
	int len = vsort.size();

	for (int i = K; i <= len; i += K)
	{
		for (int j = i - 1; j >= i - K; --j)
		{
			vout.push_back(vsort[j]);
		}
	}
	for (int i = (len / K)*K; i < len; ++i)
	{
		vout.push_back(vsort[i]);
	}

	for (int i = 0; i < len - 1; ++i)
	{
		vout[i].next = vout[i + 1].address;
		printf("%05d %d %05d\n", vout[i].address, vout[i].data, vout[i].next);
	}
	printf("%05d %d -1", vout[len - 1].address, vout[len - 1].data);
}

void Pat1026()
{
	int C1, C2;
	scanf("%d %d", &C1, &C2);
	int progRunTime = (int)((double)(C2 - C1) / 100 + 0.5f);
	int hh = progRunTime / (60 * 60);
	int mm = (progRunTime % (60 * 60)) / 60;
	int ss = (progRunTime % (60 * 60)) % 60;
	printf("%02d:%02d:%02d", hh, mm, ss);
}

void Pat1027()
{
	int N;
	char c;
	int sum = 1, count = 1, i = 1, remain = 0;
	scanf("%d %c", &N, &c);
	for (i = 1;; ++i)
	{
		count += 2;
		sum = sum + ((i * 2) + 1) * 2;
		if (sum > N)
			break;
	}
	sum = sum - ((i * 2) + 1) * 2;
	count -= 2;
	remain = N - sum;
	for (i = 0; i < count; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if ((j >= i && j <= count - 1 - i) || (j <= i&&j >= count - 1 - i))
			{
				printf("%c", c);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("%d\n", remain);
}

//���ñ��������뷽ʽ����ֱ�ӱȽ����գ���������д�жϱ߽纯��
//ע��Ϸ�����Ϊ0�����
void Pat1028()
{
	int N, count = 0;
	char birth[11], oBirth[11], yBirth[11], oldest[6], youngest[6], tmp[6];
	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
	{
		scanf("%s %s", tmp, birth);
		if (strcmp(birth, "2014/09/06") <= 0 &&
			strcmp(birth, "1814/09/06") >= 0 &&
			!count)
		{
			++count; strcpy(oldest, tmp); strcpy(oBirth, birth); strcpy(youngest, tmp); strcpy(yBirth, birth); continue;
		}
		if (strcmp(birth, "2014/09/06") <= 0 &&
			strcmp(birth, "1814/09/06") >= 0)
		{
			++count;
			if (strcmp(birth, oBirth) < 0){ strcpy(oldest, tmp); strcpy(oBirth, birth); }
			if (strcmp(birth, yBirth) > 0){ strcpy(youngest, tmp); strcpy(yBirth, birth); }
		}
	}
	if (count)
		printf("%d %s %s", count, oldest, youngest);
	else
		printf("0\n");
}

void Pat1029()
{
	char srcStr[85], destStr[85];
	scanf("%s %s", srcStr, destStr);
	int srcLength = strlen(srcStr), destLength = strlen(destStr);
	char a[35];
	int i = 0, j = 0, k = 0;
	bool isFound = false;
	for (i = 0; i < srcLength; ++i)
	{
		if (srcStr[i] != destStr[j])
		{
			isFound = false;
			if (srcStr[i] >= 97 && srcStr[i] <= 122)
			{
				for (int pos = 0; pos < k; ++pos)
				{
					if (a[pos] == srcStr[i] - 32)
					{
						isFound = true;
						break;
					}
				}
				if (!isFound)
				{
					a[k] = srcStr[i] - 32;
					++k;
				}
			}
			else
			{
				for (int pos = 0; pos < k; ++pos)
				{
					if (a[pos] == srcStr[i])
					{
						isFound = true;
						break;
					}
				}
				if (!isFound)
				{
					a[k] = srcStr[i];
					++k;
				}
			}
			continue;
		}
		else
			++j;
	}
	for (int n = 0; n < k; ++n)
	{
		printf("%c", a[n]);
	}
	printf("\n");
}

void Pat1030()
{
	int N, p;
	scanf("%d %d", &N, &p);
	int v[100004];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &v[i]);
	}
	sort(v, v + N);
	int min = v[0], mCount = 0, mPos = 0;
	int mp = min * p;
	int count = 0;
	bool flag = true;
	for (int i = 0; i < N; ++i)
	{
		min = v[i];
		mp = min * p;
		count = 0;
		for (int j = i; j < N; ++j)
		{
			if (mp>v[N - 1] && N - 1 - i < mCount)
			{
				flag = false;
				break;
			}
			if (mp >= v[j])
			{
				count += 1;
				if (count > mCount)
				{
					mCount = count;
				}
			}
			else
			{
				break;
			}
		}
		if (!flag)
			break;
	}
	printf("%d\n", mCount);
}

void Pat1031()
{
	int N;
	int q[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char zm[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	const int length = 17;
	int sum = 0, a = 0;
	bool isAllPassed = true, isRight = true;
	scanf("%d", &N);
	char id[20];
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", id);
		sum = 0;
		isRight = true;
		for (int j = 0; j < length; ++j)
		{
			int tmp = id[j] - '0';
			if (tmp >= 0 && tmp <= 9)
			{
				sum = sum + tmp * q[j];
			}
			else
			{
				isAllPassed = false;
				isRight = false;
				break;
			}
		}
		if (isRight)
		{
			a = sum % 11;
			if (id[length] != zm[a])
			{
				isAllPassed = false;
				isRight = false;
			}
		}
		if (!isRight)
			printf("%s\n", id);
	}
	if (isAllPassed)
		printf("All passed\n");
}

typedef struct info{
	int id;
	int score;
}info;

bool compareStruct(info a, info b)
{
	return a.id < b.id;
}

int cmpInfo(const void *a, const void *b)
{
	return (*(info*)a).id > (*(info*)b).id;
}

void Pat1032()
{
	int N;
	info ifo[100001];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &ifo[i].id, &ifo[i].score);
	}
	qsort(ifo, N, sizeof(info), cmpInfo);
	int maxSum = -1, scoreSum = 0, maxID = 1, curID = 1;
	for (int i = 0; i < N; ++i)
	{
		if (ifo[i].id != curID)
		{
			if (scoreSum > maxSum)
			{
				maxSum = scoreSum;
				maxID = curID;
			}
			scoreSum = ifo[i].score;
			curID = ifo[i].id;
		}
		else
		{
			scoreSum += ifo[i].score;
		}
	}
	if (scoreSum>maxSum){ maxSum = scoreSum; maxID = curID; }
	printf("%d %d\n", maxID, maxSum);
}

void Pat1033()
{
	char str[45];
	char txt[100001];
	gets(str);
	gets(txt);
	int isUpper = 1;
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] == '+')
		{
			isUpper = 0;
			break;
		}
	}
	for (int i = 0; str[i] != '\0'; ++i)
	{
		for (int j = 0; txt[j] != '\0'; ++j)
		{
			if (!isUpper)
			{
				if (txt[j] >= 65 && txt[j] <= 90)
				{
					txt[j] = '*';
				}
			}
			if ((str[i] >= 'A'&&str[i] <= 'Z') || (str[i] >= 'a'&&str[i] <= 'z'))
			{
				if (str[i] == txt[j] || str[i] + 32 == txt[j])
					txt[j] = '*';
			}
			else
			{
				if (str[i] == txt[j])
					txt[j] = '*';
			}
		}
	}
	for (int i = 0; txt[i] != '\0'; ++i)
	{
		if (txt[i] != '*' && txt[i] != '+')
			printf("%c", txt[i]);
	}
	printf("\n");
}

//�������Լ���������ʾ
//���ӡ���ĸ�����ͷ�Χ��������������˺���ܻᳬ�����η�Χ
void Pat1034()
{

}
//δ���
void Pat1035()
{
	int N;
	scanf("%d", &N);
	int a[100], b[100];
	bool isInsertSort = false;
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < N - 1; ++i)
	{
		if (a[i + 1] < a[i])
		{
			int j = i;
			int tmp = a[i + 1];
			while (j >= 0 && a[j] > tmp)
			{
				a[j + 1] = a[j];
				--j;
			}
			a[j + 1] = tmp;
			int k;
			for (k = 0; k < N; ++k)
			{
				if (a[k] != b[k])
					break;
			}
			if (k == N - 1)
				isInsertSort = true;
		}
	}
}

void Pat1036()
{
	int N;
	char c;
	scanf("%d %c", &N, &c);
	int row = N / 2.0f + 0.5f;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == 0 || i == row - 1)
				printf("%c", c);
			else
			{
				if (j == 0 || j == N - 1)
					printf("%c", c);
				else
					printf(" ");
			}
		}
		printf("\n");
	}
}
//17S->1G
//29K->1S
//
void Pat1037()
{
	typedef struct money{
		int Galleon;
		int Sickle;
		int Knut;
	}money;
	money needMoney, payMoney;
	const int kTos = 29;
	const int sToG = 17;
	scanf("%d.%d.%d %d.%d.%d", &needMoney.Galleon, &needMoney.Sickle, &needMoney.Knut, &payMoney.Galleon, &payMoney.Sickle, &payMoney.Knut);
	int need = needMoney.Galleon*sToG*kTos + needMoney.Sickle*kTos + needMoney.Knut;
	int pay = payMoney.Galleon*sToG*kTos + payMoney.Sickle*kTos + payMoney.Knut;
	if (pay >= need)
	{
		int remain = pay - need;
		int remainK = remain % kTos;
		remain = remain / kTos;
		int remainS = remain % sToG;
		remain = remain / sToG;
		printf("%d.%d.%d\n", remain, remainS, remainK);
	}
	else
	{
		int remain = need - pay;
		int remainK = remain % kTos;
		remain = remain / kTos;
		int remainS = remain % sToG;
		remain = remain / sToG;
		printf("-%d.%d.%d\n", remain, remainS, remainK);
	}
}

void Pat1038()
{
	int N, K, score[101];
	scanf("%d", &N);
	for (int i = 0; i < 101; ++i)score[i] = 0;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		++score[tmp];
	}
	scanf("%d", &K);
	for (int i = 0; i < K; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (i != K - 1)printf("%d ", score[tmp]);
		else printf("%d", score[tmp]);
	}
	printf("\n");
}

void Pat1039()
{
	typedef struct bead{
		char color;
		int num;
	}bead;
	bead b[62];
	int count = 0;
	char src[1001], dest[1001];
	scanf("%s %s", dest, src);
	int srcLength = strlen(src);
	int destLength = strlen(dest);
	for (int i = 0; i < srcLength; ++i)
	{
		if (i == 0)
		{
			b[count].color = src[i];
			b[count].num = 1;
			count += 1;
		}
		else
		{
			for (int j = 0; j < count; ++j)
			{
				if (b[j].color != src[i] && j == count - 1)
				{
					b[count].color = src[i];
					b[count].num = 1;
					count += 1;
					break;
				}
				else
				{
					if (b[j].color == src[i])
					{
						b[j].num += 1;
						break;
					}
				}
			}
		}
	}
	for (int i = 0; i < destLength; ++i)
	{
		for (int j = 0; j < count; ++j)
		{
			if (b[j].color == dest[i])
			{
				if (b[j].num != 0)
				{
					b[j].num -= 1;
					break;
				}
				else
					break;
			}
		}
	}
	bool canBuy = true;
	int lackSum = 0;
	for (int i = 0; i < count; ++i)
	{
		if (b[i].num != 0)
		{
			lackSum += b[i].num;
			canBuy = false;
		}
	}
	if (canBuy)
	{
		printf("Yes %d", destLength - srcLength);
	}
	else
	{
		printf("No %d", lackSum);
	}
}

void Pat1040()
{

}

void Pat1041()
{
	typedef struct info{
		char id[14];
		int testID;
		int examID;
	}info;
	info ifo[1000];
	int N, M, checkAry[1000];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s %d %d", ifo[i].id, &ifo[i].testID, &ifo[i].examID);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &checkAry[i]);
		for (int j = 0; j < N; ++j)
		{
			if (ifo[j].testID == checkAry[i])
			{
				printf("%s %d\n", ifo[j].id, ifo[j].examID);
				break;
			}
		}
	}
}

void Pat1042()
{
	char str[1000];
	int num[26];
	for (int i = 0; i < 26; ++i)
	{
		num[i] = 0;
	}
	gets(str);
	int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] >= 65 && str[i] <= 90)
			num[str[i] - 65] += 1;
		if (str[i] >= 97 && str[i] <= 122)
			num[str[i] - 97] += 1;
	}
	int maxNdx = 0;
	for (int i = 1; i < 26; ++i)
	{
		if (num[maxNdx] < num[i])
		{
			maxNdx = i;
		}
	}
	printf("%c %d\n", maxNdx + 97, num[maxNdx]);
}

void Pat1043()
{
	char str[10000];
	gets(str);
	int num[6];
	int sum = 0;
	for (int i = 0; i < 6; ++i)
	{
		num[i] = 0;
	}
	int length = strlen(str);
	for (int i = 0; i < length; ++i)
	{
		if (str[i] == 'P')num[0] += 1;
		if (str[i] == 'A')num[1] += 1;
		if (str[i] == 'T')num[2] += 1;
		if (str[i] == 'e')num[3] += 1;
		if (str[i] == 's')num[4] += 1;
		if (str[i] == 't')num[5] += 1;
		if (str[i] == 'P' || str[i] == 'A' || str[i] == 'T' || str[i] == 'e' || str[i] == 's' || str[i] == 't')
			sum += 1;
	}
	while (sum)
	{
		for (int i = 0; i < 6; i++)
		{
			if (num[i] != 0)
			{
				num[i] -= 1;
				sum -= 1;
				if (i == 0)printf("P");
				if (i == 1)printf("A");
				if (i == 2)printf("T");
				if (i == 3)printf("e");
				if (i == 4)printf("s");
				if (i == 5)printf("t");
			}
		}
	}
	printf("\n");
}

//����
void Pat1044()
{

}

void Pat1045()
{

}

void Pat1046()
{
	int N;
	int a1, a2, b1, b2, c1, c2;
	c1 = c2 = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %d %d", &a1, &a2, &b1, &b2);
		if (a1 + b1 == a2&&a1 + b1 == b2)
			continue;
		if (a1 + b1 == a2)
			c2 += 1;
		if (a1 + b1 == b2)
			c1 += 1;
	}
	printf("%d %d\n", c1, c2);
}

void Pat1047()
{
	int N;
	int teamScore[1001], teamID, stuID, score, maxScoreTeamID;
	for (int i = 1; i < 1001; ++i)
	{
		teamScore[i] = 0;
	}
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d-%d %d", &teamID, &stuID, &score);
		teamScore[teamID] += score;
	}
	maxScoreTeamID = 1;
	for (int i = 2; i < 1001; ++i)
	{
		if (teamScore[i]>teamScore[maxScoreTeamID])
			maxScoreTeamID = i;
	}
	printf("%d %d\n", maxScoreTeamID, teamScore[maxScoreTeamID]);
}

//����ĵط�Ҫ����
void Pat1048()
{
	char A[101], B[101];
	scanf("%s %s", A, B);
	int c = strlen(A) - strlen(B), maxLen = max(strlen(A), strlen(B)), pos = 1;
	if (c>0)
	{
		int len = strlen(B);
		++len;
		while (len >= 0){ B[len + c] = B[len]; --len; }
		while (c--)B[c] = '0';
	}
	else
	{
		c = abs(c);
		int len = strlen(A);
		++len;
		while (len >= 0){ A[len + c] = A[len]; --len; }
		while (c--)A[c] = '0';
	}
	for (int i = maxLen - 1; i >= 0; --i)
	{
		if (pos % 2 == 0)
		{
			int tmp = B[i] - A[i];
			if (tmp<0)tmp += 10;
			B[i] = tmp + '0';
		}
		else
		{
			int tmp = (A[i] - '0' + B[i] - '0') % 13;
			if (tmp < 10)B[i] = tmp + '0';
			else
			{
				if (tmp == 10)B[i] = 'J';
				if (tmp == 11)B[i] = 'Q';
				if (tmp == 12)B[i] = 'K';
			}
		}
		++pos;
	}
	printf("%s\n", B);
}

void Pat1049()
{
	int N;
	scanf("%d", &N);
	double d[100000];
	double sum = 0.0f;
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &d[i]);
		sum += d[i] * (N - i)*(i + 1);
	}
	printf("%.2lf\n", sum);
}
//
//
//
void Pat1050()
{
	int N;
	scanf("%d", &N);
	int m = 1, n = 1, minValue = N;
	int ary[10000], matrix[100][100];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &ary[i]);
	}
	for (int i = 1; i < 101; ++i)
	{
		for (int j = 1; j < 101; ++j)
		{
			if (i*j == N && i >= j&&i - j < minValue)
			{
				m = i;
				n = j;
				minValue = m - n;
			}
		}
	}
}

void Pat1051()
{
	double R1, P1, R2, P2;
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
	double a1 = R1 * cos(P1), b1 = R1 * sin(P1);
	double a2 = R2 * cos(P2), b2 = R2 * sin(P2);
	if (b1*a2 + a1*b2 < 0)
		if (a1*a2 - b1*b2 != 0)printf("%.2lf%.2lfi\n", a1*a2 - b1*b2, b1*a2 + a1*b2); else printf("%.2lfi\n", b1*a2 + a1*b2);
	else if (b1*a2 + a1*b2 > 0)
		if (a1*a2 - b1*b2 != 0)printf("%.2lf+%.2lfi\n", a1*a2 - b1*b2, b1*a2 + a1*b2); else printf("%.2lfi\n", b1*a2 + a1*b2);
	else
		if (a1*a2 - b1*b2 != 0)printf("%.2lf\n", a1*a2 - b1*b2); else printf("0");
}
//
void Pat1052()
{
	int N, D;
	double e;
	scanf("%d %lf %d", &N, &e, &D);
	int maybeNullNum = 0, nullNum = 0;
	for (int i = 0; i < N; ++i)
	{
		
	}
}

//
void Pat1053()
{
	int N, D, K, count = 0, nullRoom = 0, mayNullRoom = 0;
	double e;
	scanf("%d %lf %d", &N, &e, &D);
	for (int i = 0; i<N; ++i)
	{
		scanf("%d", &K);
		count = 0;
		for (int j = 0; j<K; ++j)
		{
			double tmp;
			scanf("%lf", &tmp);
			if (tmp<e)++count;
		}
		if (count >= K / 2 + 1)
			if (K > D)++nullRoom; else++mayNullRoom;
	}
	printf("%.1lf%% %.1lf%%\n", (double)mayNullRoom / N * 100, (double)nullRoom / N * 100);
}

void Pat1054()
{
	int N, count = 0;
	scanf("%d", &N);
	double d, sum = 0.0f;
	char str[100];
	for (int i = 0; i < N; ++i)
	{		
		scanf("%s", str);
		int dotNum = 0, dotNumberNum = 0, flag = 1, j = 0;
		for (j; str[j] != '\0'; ++j)
		{
			if (str[j] == '-'&& j == 0)continue;
			if ((str[j] < 48 || str[j]>57) && str[j] != '.'){ flag = 0; break; }
			if (str[j] == '.'&& dotNum){ flag = 0; break; }
			if (dotNum)dotNumberNum += 1;
			if (str[j] == '.')dotNum += 1;
			if (dotNumberNum > 2){ flag = 0; break; }
		}

		if (flag && atof(str) >= -1000 && atof(str) <= 1000)
		{
			sum += atof(str);
			count += 1;
		}
		else
		{
			printf("ERROR: %s is not a legal number\n", str);
		}

		//int length = strlen(str);
		//d = strtod(str, &endPtr);
		//char *dotPtr = strchr(str, '.');
		//int dotRight = 0;
		//if (dotPtr)
		//{
		//	int dotLength = strlen(dotPtr);
		//	if (dotLength == 2 || dotLength == 3)
		//	{
		//		int dotNum = 0;
		//		for (int j = 1; j < dotLength; ++j)
		//		{
		//			if (dotPtr[j] == '.')
		//			{
		//				dotNum += 1;
		//			}
		//		}
		//		if (dotNum >= 1)
		//			dotRight = 0;
		//		else
		//			dotRight = 1;
		//	}
		//}
		//else
		//	dotRight = 1;
		//if (d < -1000 ||
		//	d>1000 ||
		//	!dotRight ||
		//	*endPtr)
		//{
		//	printf("ERROR: %s is not a legal number\n", str);
		//}
		//else
		//{
		//	sum += d;
		//	count += 1;
		//}
	}
	if (count == 0)
		printf("The average of 0 numbers is Undefined\n");
	if (count == 1)
		printf("The average of 1 numbers is %.2lf\n", sum);
	if (count >= 2)
		printf("The average of %d numbers is %.2lf\n", count, sum / count);
	
}

void Pat1055()
{

}

void Pat1056()
{
	int N, a[10], sum = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]); 
		sum += (a[i] * 10 + a[i])*(N - 1);
	}
	printf("%d\n", sum);	
}

void Pat1057()
{
	char c;
	int sum = 0, zeroCount = 0, oneCount = 0;
	while ((c = getchar()) != '\n')
	{
		if (c >= 65 && c <= 90)sum += c - 64;
		if (c >= 97 && c <= 122)sum += c - 96;
	}
	if (sum)++oneCount;
	while (sum / 2)
	{
		if (sum % 2)++oneCount; else ++zeroCount;
		sum = sum / 2;
	}
	printf("%d %d\n", zeroCount, oneCount);
}

void Pat1058()
{
	typedef struct studentOption{
		int num;
		char stuChoose[5];
	}studentOption;
	typedef struct option{
		int score;
		int optionNum;
		int rightNum;
		char rightChoose[5];
	};
	studentOption stuOpt[1001];
	option opt[101];
	for (int i = 1; i < 101; ++i)
		for (int j = 0; j < 5; ++j)
			opt[i].rightChoose[j] = '\0';
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= M; ++i)
	{
		scanf("%d %d %d", &opt[i].score, &opt[i].optionNum, &opt[i].rightNum);
		for (int j = 0; j < opt[i].rightNum; ++j)
			opt[i].rightChoose[j] = getchar();
	}
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
		{
			getchar();
			scanf("%d", &stuOpt[i].num);
			for (int k = 0; k < stuOpt[i].num; ++k)
				stuOpt[i].stuChoose[k] = getchar();
			getchar();
		}
}

void Pat1059()
{
	int N, K, flag, i, j;
	int rank[10001], id[10001], prime[10001];
	prime[1] = 0;
	id[1] = 0;
	for (int i = 2; i <= 10000; ++i)
	{
		prime[i] = 1;
		id[i] = 0;
		for (int j = 2; j <= sqrt(i); ++j)
			if (i%j == 0){ prime[i] = 0; break; }
	}
	scanf("%d", &N);
	for (i = 1; i <= N; ++i)scanf("%d", &rank[i]);
	scanf("%d", &K);
	for (i = 1; i <= K; ++i)
	{
		int tmp;
		scanf("%d", &tmp);
		if (id[tmp] == 0)
		{
			for (j = 1; j <= N; ++j)
			{
				if (rank[j] == tmp)
				{
					if (j == 1)printf("%04d: Mystery Award\n", tmp);
					else if (prime[j])printf("%04d: Minion\n", tmp);
					else printf("%04d: Chocolate\n", tmp);
					id[tmp] = 1;
					break;
				}
			}
			if (j > N){ printf("%04d: Are you kidding?\n", tmp); id[tmp] = -1; }
		}
		else if (id[tmp] == -1)printf("%04d: Are you kidding?\n", tmp);
		else printf("%04d: Checked\n", tmp);
	}
}

void Pat1060()
{
	
}

void Pat1061()
{
	int N, M, score[100], answer[100];
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &score[i]);
	}
	for (int i = 0; i < M; ++i)
	{
		scanf("%d", &answer[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		int tmp, sum = 0;
		for (int j = 0; j < M; ++j)
		{		
			scanf("%d", &tmp);
			if (tmp == answer[j])sum += score[j];
		}
		printf("%d\n", sum);
	}	
}

int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

//��Ҫ�ø����ͣ����о�����ʧ
//���Լ�����ܵ���K����(���Ե�4)
void Pat1062()
{
	int N1, M1, N2, M2, K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
	if (N1*M2>M1*N2)
	{
		int tmp;
		tmp = N1; N1 = N2; N2 = tmp;
		tmp = M1; M1 = M2; M2 = tmp;
	}
	int i = 1, k[1000], pos = 0, flag = 1;
	while (N1*K >= i*M1)++i;
	while (i*M2 < N2*K)
	{
		if (gcd(i, K) == 1)
		{
			k[pos] = i; ++pos;
		}
		++i;
	}
	for (i = 0; i < pos; ++i)
	{
		if (i == 0)printf("%d/%d", k[i], K);
		else printf(" %d/%d", k[i], K);
	}
	/*
	int N1, M1, N2, M2, K;
	scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
	if (N1*M2>M1*N2)
	{
		int tmp;
		tmp = N1; N1 = N2; N2 = tmp;
		tmp = M1; M1 = M2; M2 = tmp;
	}
	int i = 1, k[1000], pos = 0, flag = 1;
	while (N1*K>i*M1)++i;
	while (i*M2 < N2*K)
	{
		flag = 1;
		if (i % 2 == 0 && K % 2 == 0){ ++i; continue; }
		for (int j = 3; j <= min(i, K); j+=2)
		{			
			if (i%j == 0 && K%j == 0){ flag = 0; break; }
		}
		if (flag){ k[pos] = i; ++pos; }
		++i;
	}
	for (i = 0; i < pos; ++i)
	{
		if (i == 0)printf("%d/%d", k[i], K);
		else printf(" %d/%d", k[i], K);
	}
	
	*/
}

void Pat1063()
{
	int a, b, N;
	double max = 0.0f;
	scanf("%d", &N);
	for (int i = 0; i<N; ++i)
	{
		scanf("%d %d", &a, &b);
		if (sqrt(a*a + b*b)>max)max = sqrt(a*a + b*b);
	}
	printf("%.2lf\n", max);
}

void Pat1064()
{
	int N, num[50], tmp = 0, count = 0;
	char str[5];
	scanf("%d", &N);
	for (int i = 0; i < 50; ++i)num[i] = 0;
	for (int i = 0; i<N; ++i)
	{
		tmp = 0;
		scanf("%s", str);
		for (int j = 0; str[j] != '\0'; ++j)tmp += str[j] - '0';
		++num[tmp];
	}
	for (int i = 0; i < 50; ++i)if (num[i])++count;
	printf("%d\n", count);
	for (int i = 0; i<50; ++i)
		if (num[i]){ --count; if (count)printf("%d ", i); else printf("%d", i); }
}

void Pat1065()
{

}

void Pat1066()
{
	int M, N, A, B, replaceValue, value, count = 0;
	scanf("%d %d %d %d %d", &M, &N, &A, &B, &replaceValue);
	for (int i = 0; i<M; ++i)
		for (int j = 0; j<N; ++j)
		{
		scanf("%d", &value);
		if (value >= A&&value <= B)
			if (++count%N == 0)printf("%03d\n", replaceValue); else printf("%03d ", replaceValue);
		else
			if (++count%N == 0)printf("%03d\n", value); else printf("%03d ", value);
		}
}

//���������xxx xxxx��Ҳ����������Ϊ�գ����Բ��ʺ���scanf,
void Pat1067()
{
	char rightPsw[21], psw[100];
	int N, len = 0, count = 0;
	scanf("%s %d", rightPsw, &N);
	getchar();
	while (1)
	{
		gets(psw);
		++count;
		len = strlen(psw);
		if (len == 1 && psw[0] == '#')break;
		if ((!strcmp(rightPsw, psw)) && count <= N)
		{
			printf("Welcome in\n"); break;
		}
		else
		{
			if (count <= N)
			{
				printf("Wrong password: %s\n", psw);
				if (count == N)
				{
					printf("Account locked\n"); break;
				}
			}
		}
	}
}

void Pat1068()
{

}

void Pat1069()
{
	int M, N, S, count = 0, flag = 0, j = 0, isReward = 0;
	char name[20], str[1000][20];
	scanf("%d %d %d", &M, &N, &S);
	for (int i = 0; i<M; ++i)
	{
		++count;
		scanf("%s", name);
		isReward = 0;
		if (count == S || count - N == S)
		{
			for (int k = 0; k<j; ++k)
			{
				if (!strcmp(str[k], name))
					isReward = 1;
			}
			if (isReward)++S;
			else
			{
				printf("%s\n", name);
				strcpy(str[j++], name);
				S = count;
				flag = 1;
			}
		}
	}
	if (!flag)printf("Keep going...");
}


int cmpRope(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}

void Pat1070()
{
	int N;
	scanf("%d", &N);
	int *r = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i<N; ++i)scanf("%d", &r[i]);
	qsort(r, N, sizeof(int), cmpRope);
	double d = (double)r[0] / 2;
	for (int i = 1; i<N; ++i)
		d = (d + (double)r[i] / 2) / 2;
	printf("%d\n", (int)d * 2);
}

typedef struct peo{
	char name[10];
	int height;
}peo;

int cmpHeight(const void *a, const void *b)
{
	return (*(peo*)b).height - (*(peo*)a).height;
}

int cmpHeight2(const void *a, const void *b)
{
	return (*(peo*)a).height - (*(peo*)b).height;
}

int main()
{	
	int N, K, i = 0;
	scanf("%d %d", &N, &K);
	peo *p = (peo*)malloc(sizeof(peo)*N);
	for (i = 0; i<N; ++i)
	{
		scanf("%s %d", (*(p + i)).name, &(*(p + i)).height);
	}
	int perRow = N / K, lastRow = N % K + perRow;
	qsort(p, N, sizeof(peo), cmpHeight);
	qsort(p, lastRow, sizeof(peo), cmpHeight2);
	for (i = 0; i < lastRow; i+=2)
		printf("%s ", (*(p + i)).name);
	for (i = lastRow - 1; i > 0; i -= 2)
	{
		if (i == 1)printf("%s\n", (*(p + i)).name);
		else printf("%s ", (*(p + i)).name);
	}
	for (i = lastRow; i < N - 1 - lastRow; i+=perRow)
	{
		qsort(p + i, perRow, sizeof(peo), cmpHeight2);
		int j = i;
		for (j; j < i+perRow; j += 2)
			printf("%s ", (*(p + j)).name);
		for (j = i+perRow - 1; j > i; j -= 2)
		{
			if (j == i+1)printf("%s\n", (*(p + j)).name);
			else printf("%s ", (*(p + j)).name);
		}
	}
	return 0;
}