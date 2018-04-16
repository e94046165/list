#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define offsetof(type, member) ((size_t)&((type *)0)->member)
#define container_of(ptr, type, member)                            \
    __extension__({                                                \
        const __typeof__(((type *) 0)->member) *__pmember = (ptr); \
        printf("__pmember address:%p\n", __pmember);						   \
		(type *) ((char *) __pmember - offsetof(type, member));    \
    })

typedef struct student_info
 {
     int  id;
     char name[32];
     int  age;
}student_info;

int main()
{	

	size_t off_set = 0;
    off_set = offsetof(student_info, id); 
     
	printf("id offset: %u\n",off_set);
    off_set = offsetof(student_info, name);
    printf("name offset: %u\n",off_set);
    off_set = offsetof(student_info, age);
    printf("age offset: %u\n",off_set);
	printf("\n");
     
	student_info *stu = (student_info *)malloc(sizeof(student_info));
    printf("stu->age address:%p\n", &(stu->age));
    
	student_info *ptr = container_of(&(stu->age), student_info, age);
	printf("\n");
	
     printf("stu address:%p\n", stu);
     printf("ptr address:%p\n", ptr);
     return 0;
}





