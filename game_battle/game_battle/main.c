#include <stdio.h>
#include <stdlib.h>

struct param
{
	char name[8];
	int life, attack, magic;
};

void act(struct param* actor, struct param* target, int command)
{
	int point;
	switch (command)
	{
	case 0:
		point = actor->attack;
		target->life -= point;
		printf("%s attacks! %s takes %d damage points!\n", actor->name, target->name, point);
		break;
	case 1:
		point = 20;
		actor->attack += point;
		printf("%s casts Boost! %s's Attack increases by %d!\n", actor->name, actor->name, point);
		break;
	case 2:
		point = 50;
		actor->life += point;
		printf("%s casts Heal! %s's Life increases by %d!\n", actor->name, actor->name, point);
		break;
	}
}

int main(void)
{
	struct param you = { "CS", 75, 20, 10 };//CS,•Ší–³‚µ
	struct param enemy = { "enemy1", 50, 5, 0 };
	printf("%s appears!\n", enemy.name);
	for (; ; )
	{
		int command;
		printf("%s: Life=%d, Attack=%d, Magic=%d\n", you.name, you.life, you.attack, you.magic);
		printf("%s: Life=%d, Attack=%d, Magic=%d\n", enemy.name, enemy.life, enemy.attack, enemy.magic);
		//printf("(0) Attack\n(1) MagicAttack\n(2) Heal\n");
		//printf("Command:");
		//scanf("%d", &command);
		if (you.life > 25 || enemy.life <= 20) {
			command = 0;
		}
		else if (you.life <= 25 && enemy.life < 20) {
			command = 2;
		}
		act(&you, &enemy, command);
		if (enemy.life <= 0)
		{
			printf("%s is defeated!\n", enemy.name);
			return 0;
		}
		act(&enemy, &you, 0);
		if (you.life <= 0)
		{
			printf("%s has been killed...\n", you.name);
			return 0;
		}
	}
}