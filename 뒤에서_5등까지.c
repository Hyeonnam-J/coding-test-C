#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len�� �迭 num_list�� �����Դϴ�.
int* main(int num_list[], size_t num_list_len) {
	/*
		���� ����
		
		������ �̷���� ����Ʈ num_list�� �־����ϴ�. 
		num_list���� ���� ���� 5���� ���� ������������ ���� ����Ʈ�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
		
		���ѻ���
		
		6 �� num_list�� ���� �� 30
		1 �� num_list�� ���� �� 100
		
		����� ��
		
		num_list					result
		[12, 4, 15, 46, 38, 1, 14]	[1, 4, 12, 14, 15]
		
		����� �� ����
		
		����� �� #1
		[12, 4, 15, 46, 38, 1, 14]�� �����ϸ� [1, 4, 12, 14, 15, 38, 46]�� �ǰ�, �տ��� ���� 5���� ���� [1, 4, 12, 14, 15]�� �˴ϴ�.
	*/

    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    for(int i = 0; i < num_list_len; i++){
        for(int j = i; j <num_list_len; j++){
            if(num_list[i] > num_list[j]){
                int temp = num_list[i];
                num_list[i] = num_list[j];
                num_list[j] = temp;
            }
        }
    }
    
    return num_list;
}
