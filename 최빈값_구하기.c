#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len�� �迭 array�� �����Դϴ�.
int main() {
	
	/*
		���� ����
			
		�ֺ��� �־��� �� �߿��� ���� ���� ������ ���� �ǹ��մϴ�. 
		���� �迭 array�� �Ű������� �־��� ��, �ֺ��� return �ϵ��� solution �Լ��� �ϼ��غ�����. 
		�ֺ��� ���� ���� -1�� return �մϴ�.
		
		���ѻ���
		
		0 < array�� ���� < 100
		0 �� array�� ���� < 1000
		
		����� ��
		
		array				result
		[1, 2, 3, 3, 3, 4]	3
		[1, 1, 2, 2]		-1
		[1]					1
		
		����� �� ����
		
		����� �� #1
		[1, 2, 3, 3, 3, 4]���� 1�� 1�� 2�� 1�� 3�� 3�� 4�� 1���� �ֺ��� 3�Դϴ�.
		
		����� �� #2
		[1, 1, 2, 2]���� 1�� 2�� 2�� 2���� �ֺ��� 1, 2�Դϴ�. �ֺ��� ���� ���̹Ƿ� -1�� return �մϴ�.
		
		����� �� #3
		[1]���� 1�� �����Ƿ� �ֺ��� 1�Դϴ�.
	*/

	// given
	int array[] = {0, 0, 1};
	size_t array_len = sizeof(array) / sizeof(array[0]);
	
	int i, j;
	
	int countArray[array_len][2];
	for(int i = 0; i < array_len; i++) {
        countArray[i][0] = -1;
        countArray[i][1] = -1;
    }
	
	for(int i = 0; i < array_len; i++){
		int current_value = array[i];
		bool found = false;
		
		for(int j = 0; j < array_len; j++){
			if(current_value == countArray[j][0]){
				countArray[j][1]++;
				found = true;
				break;
			}
		}
		
		if(!found){
			for(int j = 0; j < array_len; j++){
				if(countArray[j][0] == -1){
					countArray[j][0] = current_value;
					countArray[j][1] = 1;
					break;
				}
			}
		}
	}
	
    int answer = 0;
    int maxValue = 0;
    
    for(int i = 0; i < array_len; i++){
    	int isMax = countArray[i][1];
    	if(maxValue < isMax){
			maxValue = isMax;
			answer = countArray[i][0];
		}
	}
	
	int countMaxValue = 0;
	for(int i = 0; i < array_len; i++){
		if(maxValue == countArray[i][1]) countMaxValue++;
		if(countMaxValue > 1) return -1;
	}
	
    return answer;
}

/*
	���� ���� ó�� ���� max�� �Ǹ� �ǰ�, 
	�ٸ� ���� ó�� �Ϳ� �������� ������ 
	ó������ ������ ��ȸ�ϸ鼭 ���� �ʿ䰡 ������. 
*/ 
