#include"quiz.h"

void QUIZ_Init(Quiz *q, char* filename) {
	//this function reads a file, fills Question 5 times (the array Question[5] in Quiz) each Question has a question, and 3 answers.
	q->f = fopen(filename,"r");
	for(int i = 0; i<5; i++){
		char buf[255];
		fgets(buf, sizeof(buf),q->f);
		strcpy(q->questions[i].question,buf);
		fgets(buf, sizeof(buf),q->f);
		strcpy(q->questions[i].reponse1,buf);
		fgets(buf, sizeof(buf),q->f);
		strcpy(q->questions[i].reponse2,buf);
		fgets(buf, sizeof(buf),q->f);
		strcpy(q->questions[i].reponse3,buf);
	}

	fclose(q->f);
}
