#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Goods {
	int num;
	char name[10];
	char sort[10];
	char brand[10];
	float price;
	int kucun;
}good[20];
void menu() {		//�˵�
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\
	\n��ӭʹ���ľߵ���Ʒ������ϵͳ\
	\n1.����¼���ʼ��Ʒ��Ϣ\
	\n2.�����Ʒ��Ϣ\
	\n3.��ѯ��Ʒ��Ϣ\
	\n4.������Ʒ��Ϣ\
	\n5.ɾ����Ʒ��Ϣ\
	\n6.�޸���Ʒ��Ϣ\
	\n7.�����ͳ����Ʒ����\
	\n8.���۸����Ʒ����\
	\n9.�õ���ǰ�����Ʒ���ܼ�ֵ\
	\n10.�˳�\
	\nллʹ��\
	\n");
}
void write(int cnt) {		//����������������txt����
	int num;
	char name[10];
	char sort[10];
	char brand[10];
	float price;
	int kucun;
	int i;
	FILE* fp;
	fp = fopen("test.txt", "a");
	if (fp == NULL) {
		printf("�޷��򿪴��ļ�");
		exit(0);
	}
	for (i = 0; i < cnt; i++) {
		scanf("%d%s%s%s%f%d", &num, name, sort, brand, &price, &kucun);
		fprintf(fp, "%d\t%s\t%s\t%s\t%f\t%d", num, name, sort, brand, price, kucun);
	}
	fclose(fp);
}

int luru() {		//��txt����ÿ������¼��ṹ�����
	int num;
	char name[10];
	char sort[10];
	char brand[10];
	float price;
	int kucun;
	int i = 0, j, flag = 1;
	char row[80];
	FILE* fp;

	fp = fopen("test.txt", "r");
	if (fp == NULL) {
		printf("�޷��򿪴��ļ�\n");
		exit(0);
	}
	while (fgets(row, 80, fp) != NULL) {
		sscanf(row, "%d%s%s%s%f%d", &num, name, sort, brand, &price, &kucun);
		for (j = 0; j < i; j++) {
			if (good[j].num == num) {
				printf("��Ʒ���%d�Ѵ��ڣ���������Ʒ\n", num);
				flag = 0;
			}
		}

		if (flag == 1) {
			good[i].num = num;
			strcpy(good[i].name, name);
			strcpy(good[i].sort, sort);
			strcpy(good[i].brand, brand);
			good[i].price = price;
			good[i].kucun = kucun;
			i++;
		}
	}
	printf("�ѳɹ�¼��%d����Ʒ��Ϣ\n", i);
	fclose(fp);
	return i;
}

void liulan(int cnt) {	//�����Ʒ��Ϣ
	int i;
	printf("���|��Ʒ���|��Ʒ����	|��Ʒ���|	��ƷƷ��|	��Ʒ����|��Ʒ���\n");
	for (i = 0; i < cnt; i++) {

		printf("%d\t%d\t%s\t%s\t\t%s\t\t%.2f\t%d\n", i + 1, good[i].num, good[i].name, good[i].sort, good[i].brand, good[i].price, good[i].kucun);
	}
}

void chaxun(int cnt) {	//��ѯ��Ʒ��Ϣ
	int num, flag = 0;
	void print(int i);
	printf("��ѡ���ѯ��ʽ\
	\n1.������Ʒ��Ų�ѯ\
	\n2.������Ʒ���Ʋ�ѯ\
	\n3.������ƷƷ�Ʋ�ѯ\
	\n4.������Ʒ����ѯ\
	\n����������ѡ��1-4����\n");
	scanf("%d", &num);
	switch (num) {
	case 1: {
		int no, i;
		printf("��������Ʒ��ţ�");
		scanf("%d", &no);
		for (i = 0; i < cnt; i++)
			if (no == good[i].num)
			{
				print(i); flag = 1;
			}

		if (flag == 0) printf("δ��ѯ����Ʒ��Ϣ��\n");
		break;
	}
	case 2: {
		int i;
		char name[10];
		printf("��������Ʒ���ƣ�");
		scanf("%s", name);
		for (i = 0; i < cnt; i++)
			if (strcmp(name, good[i].name) == 0)
			{
				print(i); flag = 1;
			}
		if (flag == 0) printf("δ��ѯ����Ʒ��Ϣ��\n");
		break;
	}
	case 3: {
		int i;
		char brand[10];
		printf("��������ƷƷ�ƣ�");
		scanf("%s", brand);
		for (i = 0; i < cnt; i++)
			if (strcmp(brand, good[i].brand) == 0)
			{
				print(i); flag = 1;
			}
		if (flag == 0) printf("δ��ѯ����Ʒ��Ϣ��\n");
		break;
	}
	case 4: {
		int i;
		char sort[10];
		printf("��������Ʒ���");
		scanf("%s", sort);
		for (i = 0; i < cnt; i++)
			if (strcmp(sort, good[i].sort) == 0)
			{
				print(i); flag = 1;
			}
		if (flag == 0) printf("δ��ѯ����Ʒ��Ϣ��\n");
		break;
	}
	default:printf("������Ч��\n");
	}
}

void print(int i) {	//��ӡ��ʽ
	printf("============================\
	\n��Ʒ��ţ�	%d\
				\n��Ʒ���ƣ�	%s\
				\n��Ʒ���	%s\
				\n��ƷƷ�ƣ�	%s\
				\n��Ʒ�۸�	%.2f\
				\n��Ʒ���:	%d\n", good[i].num, good[i].name, good[i].sort, good[i].brand, good[i].price, good[i].kucun);
}

void zenjia() {	//������Ʒ��Ϣ
	int num, sor, bra;
	char name[10];
	char sort[4][10] = { "����","����","������","����" };
	char brand[5][10] = { "����","����","����","zebra","�԰ؼ�" };
	float price;
	int kucun;
	FILE* fp;
	fp = fopen("test.txt", "a");
	if (fp == NULL) {
		printf("�޷��򿪴��ļ�");
		exit(0);
	}
	printf("������������Ʒ��Ϣ~\n��������Ʒ��ţ�");
	scanf("%d", &num);
	printf("��������Ʒ���ƣ�");
	scanf("%s", name);
	printf("��������Ʒ���(1.����,2.����,3.������,4.����)��");
	scanf("%d", &sor);
	printf("��������ƷƷ��(1.����,2.����,3.����,4.zebra,5.�԰ؼ�)��");
	scanf("%d", &bra);
	printf("��������Ʒ�۸�");
	scanf("%f", &price);
	printf("��������Ʒ��棺");
	scanf("%d", &kucun);
	fprintf(fp, "%d\t%s\t\t%s\t\t%s\t\t%.2f\t%d\n", num, name, sort[sor - 1], brand[bra - 1], price, kucun);
	printf("��Ʒ��Ϣ�ѳɹ����\n��Ʒ��Ϣ�ѳɹ����浽test.txt\n");
	fclose(fp);
}

void shanchu(int cnt) {	//ɾ����Ʒ��Ϣ
	int op, i, flag = 0, flag1 = 0;	//flag�Ǳ�ʾ�Ƿ�ȷ��ɾ��,flag1��ʾ��û��¼�����Ʒ��Ϣ
	char op1;
	int num, fnum;
	char name[10], fname[10];
	char sort[10];
	char brand[10];
	char* filename = "test.txt";
	float price;
	int kucun;
	char row[80];//row��������,row1�����ݴ�����ļ�ÿһ�е�����

	printf("��ѡ��ɾ����ʽ��\n1.����Ʒ���ɾ��\n2.����Ʒ����ɾ��\n�������ѡ��");
	scanf("%d", &op);
	if (!(op == 1 || op == 2)) printf("���벻����Ҫ��\n");
	else {
		if (op == 1) {
			printf("������Ҫɾ������Ʒ��ţ�");
			scanf("%d", &num);
			op1 = getchar();	//�滻��
			FILE* fd, * fx;
			fd = fopen(filename, "r");
			fx = fopen("temp.txt", "w");

			//			if(cnt==0) printf("��δ¼����Ʒ��Ϣ~");
			if (fd == NULL || fx == NULL) {
				printf("�޷��򿪴��ļ�\n");
				exit(0);
			}
			for (i = 0; i < cnt; i++) {

				while (fgets(row, 80, fd) != NULL) {
					sscanf(row, "%d%s%s%s%f%d", &fnum, fname, sort, brand, &price, &kucun);
					if (num == fnum) {
						flag1 = 1;
						print(i);
						printf("�Ƿ�ȷ��ɾ����(y/n):");
						op1 = getchar();
						if (op1 == 'n') {
							flag = 1; break;
						}
					}

					if (num != fnum) {
						fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brand, price, kucun);
					}

				}
			}
			if (flag1 == 0) printf("δ¼�����Ʒ��Ϣ��\n");
			fclose(fd);
			fclose(fx);
			if (flag == 0) {
				remove(filename);
				rename("temp.txt", filename);
				if (flag1 != 0)
					printf("ɾ���ɹ�\n");
			}
		}
		if (op == 2) {
			printf("������Ҫɾ������Ʒ���ƣ�");
			scanf("%s", name);
			op1 = getchar();	//�滻��
			FILE* fd, * fx;
			fd = fopen(filename, "r");
			fx = fopen("temp.txt", "w");

			//			if(cnt==0) printf("��δ¼����Ʒ��Ϣ~");
			if (fd == NULL || fx == NULL) {
				printf("�޷��򿪴��ļ�\n");
				exit(0);
			}
			for (i = 0; i < cnt; i++) {

				while (fgets(row, 80, fd) != NULL) {
					sscanf(row, "%d%s%s%s%f%d", &fnum, fname, sort, brand, &price, &kucun);
					if (strcmp(fname, name) == 0) {
						flag1 = 1;
						print(i);
						printf("�Ƿ�ȷ��ɾ����(y/n):");
						op1 = getchar();
						if (op1 == 'n') {
							flag = 1; break;
						}
					}

					if (strcmp(fname, name) != 0) {
						fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brand, price, kucun);
					}

				}
			}
			if (flag1 == 0) printf("δ¼�����Ʒ��Ϣ��\n");
			fclose(fd);
			fclose(fx);
			if (flag == 0) {

				remove(filename);
				rename("temp.txt", filename);
				if (flag1 != 0)
					printf("ɾ���ɹ�\n");
			}
		}
	}
}


void xiugai(int cnt) {	//�޸���Ʒ��Ϣ
	int i, op;
	int main();
	int num, fnum;
	char newname[10], fname[10];
	char sort[10];
	char brand[10];
	char row[80];
	float price, newprice;
	int kucun, newkucun;
	int newsort, newbrand;
	int flag = 0;		//�����������ı���Ƿ����ļ�����
	char sortlst[4][10] = { "����","����","������","����" };
	char brandlst[5][10] = { "����","����","����","zebra","�԰ؼ�" };
	char filename[10] = "test.txt";
	FILE* fd, * fx;
	fd = fopen(filename, "r");
	fx = fopen("temp.txt", "w");
	printf("������Ҫ�޸ĵ���Ʒ��ţ�");
	scanf("%d", &num);
	for (i = 0; i < cnt; i++)
		if (good[i].num == num) {
			print(i); flag = 1;
		}
	if (flag == 0) printf("�޸���Ʒ��ţ�\n");
	else {

		printf("��ѡ��Ҫ�޸ĵ���Ʒ��Ϣ��\
	\n1.��Ʒ����\
	\n2.��Ʒ���\
	\n3.��ƷƷ��\
	\n4.��Ʒ����\
	\n5.��Ʒ���\
	\n������ѡ��(1-5)\n");
		scanf("%d", &op);

		switch (op) {
		case 1: {
			printf("��������Ʒ���ƣ�");
			scanf("%s", newname);
			while (fgets(row, 80, fd) != NULL) {
				sscanf(row, "%d%s%s%s%f%d", &fnum, fname, sort, brand, &price, &kucun);
				if (fnum != num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brand, price, kucun);
				}
				else if (fnum == num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, newname, sort, brand, price, kucun);
				}
			}
			//			for(i=0;i<cnt)
			break;
		}
		case 2: {
			printf("��������Ʒ���(1.����,2.����,3.������,4.����)��");
			scanf("%d", &newsort);
			while (fgets(row, 80, fd) != NULL) {
				sscanf(row, "%d%s%s%s%f%d", &fnum, fname, sort, brand, &price, &kucun);
				if (fnum != num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brand, price, kucun);
				}
				else if (fnum == num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sortlst[newsort - 1], brand, price, kucun);
				}
			}
			break;
		}
		case 3: {
			printf("��������ƷƷ��(1.����,2.����,3.����,4.zebra,5.�԰ؼ�)��");
			scanf("%d", &newbrand);
			while (fgets(row, 80, fd) != NULL) {
				sscanf(row, "%d%s%s%s%f%d", &fnum, fname, sort, brand, &price, &kucun);
				if (fnum != num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brand, price, kucun);
				}
				else if (fnum == num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brandlst[newbrand - 1], price, kucun);
				}
			}
			break;
		}
		case 4: {
			printf("��������Ʒ���ۣ�");
			scanf("%f", &newprice);
			while (fgets(row, 80, fd) != NULL) {
				sscanf(row, "%d%s%s%s%f%d", &fnum, fname, sort, brand, &price, &kucun);
				if (fnum != num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brand, price, kucun);
				}
				else if (fnum == num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brand, newprice, kucun);
				}
			}
			break;
		}
		case 5: {
			printf("��������Ʒ��棺");
			scanf("%d", &newkucun);
			while (fgets(row, 80, fd) != NULL) {
				sscanf(row, "%d%s%s%s%f%d", &fnum, fname, sort, brand, &price, &kucun);
				if (fnum != num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brand, price, kucun);
				}
				else if (fnum == num) {
					fprintf(fx, "%d\t%s\t%s\t%s\t%.2f\t%d\n", fnum, fname, sort, brand, price, newkucun);
				}
			}
			break;
		}
		default:printf("������Ч��\n");

		}
		fclose(fd);
		fclose(fx);
		remove(filename);
		rename("temp.txt", filename);
		printf("�޸ĳɹ�\n");
	}
}

void tongji(int cnt) {	//�����ͳ����Ʒ����
	int op;		//ѡ��1-4
	int n = 0, i;
	char sortlst[4][10] = { "����","����","������","����" };
	printf("��ѡ��Ҫͳ�Ƶ���Ʒ���\
	\n1.����\
	\n2.����\
	\n3.������\
	\n4.����\
	\n�����������(1-4):");
	scanf("%d", &op);
	switch (op) {
	case 1: {
		for (i = 0; i < cnt; i++) {
			if (strcmp(good[i].sort, sortlst[0]) == 0)
				n++;
		}
		printf("��Ʒ���%s�й��� %d ����Ʒ\n", sortlst[0], n);
		break;
	}
	case 2: {
		for (i = 0; i < cnt; i++) {
			if (strcmp(good[i].sort, sortlst[1]) == 0)
				n++;
		}
		printf("��Ʒ���%s�й��� %d ����Ʒ\n", sortlst[1], n);

		break;
	}
	case 3: {
		for (i = 0; i < cnt; i++) {
			if (strcmp(good[i].sort, sortlst[2]) == 0)
				n++;
		}
		printf("��Ʒ���%s�й��� %d ����Ʒ\n", sortlst[2], n);

		break;
	}
	case 4: {
		for (i = 0; i < cnt; i++) {
			if (strcmp(good[i].sort, sortlst[3]) == 0)
				n++;
		}
		printf("��Ʒ���%s�й��� %d ����Ʒ\n", sortlst[3], n);

		break;
	}
	default:printf("������Ч��\n");
	}
}

int shen(int n) {//ð������
	int i, j;
	struct Goods* p1 = good, * p2 = good;
	for (i = 0; i < n - 1; i++, p1++, p2++)
		for (j = 0; j < n - 1 - i; j++)
			if (good[j].price > good[j + 1].price) {
				*p1 = good[j + 1];
				*p2 = good[j];
			}
	for (i = 0; i < n; i++) {
		print(i);
	}
	return 0;
}

int jiang(int n) {
	int i, j;
	struct Goods* p1 = good, * p2 = good;
	for (i = 0; i < n - 1; i++, p1++, p2++)
		for (j = 0; j < n - 1 - i; j++)
			if (good[j].price < good[j + 1].price) {
				*p1 = good[j + 1];
				*p2 = good[j];
			}
	for (i = 0; i < n; i++) {
		print(i);
	}
	return 0;
}

void paixu(int cnt) {	//�����۶���Ʒ����
	int op, n = cnt;
	int i, j;
	struct Goods* p1 = good, * p2 = good, temp;
	printf("����������ʽ��\
	\n1.���۸���������\
	\n2.���۸�������\
	\n������ѡ��(1-2):");
	scanf("%d", &op);
	if (op != 1 && op != 2)printf("��Ч���룡\n");
	else {

		if (op == 1) {
			for (i = 0; i < n - 1; i++)
				for (j = 0; j < n - 1 - i; j++, p1++, p2++)
					if (good[j].price > good[j + 1].price) {
						temp = *p2;
						good[j + 1] = *p1;
						good[j] = temp;
					}
			for (i = 0; i < n; i++) {
				print(i);
			}
		}
		if (op == 2) {
			for (i = 0; i < n - 1; i++) {
				p1 = good;
				p2 = good + 1;
				for (j = 0; j < n - 1 - i; j++, p1++, p2++)
					if (p1->price < p2->price) {
						temp = *p2;
						good[j + 1] = *p1;
						good[j] = temp;
					}
			}
			for (i = 0; i < n; i++) {
				print(i);
			}
		}
	}
}

void zongjia(int cnt) {	//���㵱ǰ��Ʒ�ܼ�ֵ
	float total = 0;
	int i;
	struct Goods* p = good;
	for (i = 0; i < cnt; i++, p++) {
		total += p->price * p->kucun;
		printf("%.2f\n", p->price * p->kucun);
	}
	printf("��ǰ�ֿ�%d����Ʒ�ܼ�ֵΪ%.2f", i, total);
}

int tuichu() {
	int ch;
	printf("�Ƿ�ȷ���˳�(y/n):");
	getchar();
	ch = getchar();
	if (ch == 'y')return 0;
	else {
		if (ch != 'n' && ch != 'y')printf("������Ч\n");
		return 1;
	}

}

int main() {		//������
	int opt;
	int cnt;
	int res = 1;
	menu();
	while (res) {
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\
		\n����������ѡ��");
		scanf("%d", &opt);

		switch (opt) {
		case 1:cnt = luru(); break;
		case 2:liulan(cnt); break;
		case 3:chaxun(cnt); break;
		case 4:zenjia(); break;
		case 5:shanchu(cnt); break;
		case 6:xiugai(cnt); break;
		case 7:tongji(cnt); break;
		case 8:paixu(cnt); break;
		case 9:zongjia(cnt); break;
		case 10:res = tuichu(); break;
		default:printf("����������1-10��\n");
		}
	}
	return 0;
}
