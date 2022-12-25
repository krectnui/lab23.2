#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
struct list
{
	char name[80];
	struct listitem* next;
};
typedef struct list list;
struct list* addelem(list* lst, char name[80]);
struct list* init(char name[80]);
struct list* deletehead(list* root);
void listprint(list* lst);

int main() {
	setlocale(LC_ALL, "RUS");
	list* vars = init("David");
	addelem(vars, "Sara"); addelem(vars, "Qwtre"); addelem(vars, "asdasd"); addelem(vars, "выаозывж0"); addelem(vars, "Sываыва"); addelem(vars, "Saкк"); addelem(vars, "Sara"); addelem(vars, "Sara");
	addelem(vars, "Sara"); addelem(vars, "Sarsfd");
	listprint(vars);
}
struct list* init(char name[80])
{
	struct list* lst;

	lst = (struct list*)malloc(sizeof(struct list));

	strcpy(lst->name, name);
	lst->next = NULL;
	return(lst);
}
struct list* addelem(list* lst, char name[80])
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next;
	lst->next = temp;

	strcpy(temp->name, name);
	temp->next = p;
	return(temp);
}
struct list* deletehead(list* root)
{
	struct list* temp;
	temp = root->next;
	free(root);
	return(temp);
}
void listprint(list* lst)
{
	struct list* p;
	p = lst;
	int count = 0;

	while (p != NULL) {
		for (int i = 0; i < strlen(p->name); i++) {
			if (isalpha(p->name[i]) == 0) {
				count++;
			}
		}
		printf("Имя %s\n", p->name);
		p = p->next;
	}
	printf("Количество букв латинского алфавита в массиве %d\n", count);

}