```c

scanf("%[^\n]", &string);
printf("%s\n", string);
scanf("%*c%[^\n]", &compare);
printf("%s\n", compare);
```





```c

/* 기본적인 스트링 처리 함수들 */
int m_strlen(char *s){
    int len = 0;
    while(s[len]!='\0'){
        len++;
    }
    return len;
}
int m_strcmp(char *a, char *b){
    int i = 0;
    while (a[i]!='\0') {
        if(a[i]!=b[i])
            break;
        i++;
    }
    return (a[i]-b[i]); //같으면 0, 문자열 a가 사전순으로  빠르면 음수, b가 더 빠르면 양수를 반환
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/* 문자열을 사전순으로 비교하여 sorting*/
int partition(int low, int high){
    int index = low;
    for(int i = low; i<=high-1; i++){
        if(m_strcmp(&str[Suffix[i]], &str[Suffix[high]])<0){ //음수이면 사전순으로 정렬시 더 앞에 있다는 의미(high가 아니라 index?)
            swap(&Suffix[index], &Suffix[i]);
            index++;
        }
    }
    swap(&Suffix[index], &Suffix[high]);
    return index;
}
void quicksort(int low, int high){
    if(low >= high)
        return;
    int pivot = partition(low, high);
    quicksort(low, pivot-1);
    quicksort(pivot+1, high);
}
/* 접미어 배열 생성*/
void generate_Suffix_array(void){
    length = m_strlen(str);
    str[length] = '\0';
    for(int i = 0; i<length; i++)   //set as index
        Suffix[i] = i;
    quicksort(0, length-1);
}
/*최장 공통 접두어 길이 배열*/
int get_lcp(char *a, char *b){
    int i = 0;
    while(a[i] == b[i])
        i++;
    return i;
}
void generate_LCP_array(void){
    LCP[0] = 0;
    for(int i = 1; i<length; i++){
        LCP[i] =get_lcp(&str[Suffix[i-1]], &str[Suffix[i]]);
    }
}
/* k번째 문자열 계산 및 출력 */
int get_kth_word(int k){
    int accummulated_num_words = 0;
    int index = 0;
    while(accummulated_num_words< k && index<length){
        int startIndex = Suffix[index];
        // 출력할 lastindex =  접미어의 시작 index + LCP + (k- 이전까지의 누적 유효 부분 문자열 수) - 1
        int lastIndex = startIndex + LCP[index] + (k-accummulated_num_words)-1;
        if(lastIndex < length) {//접미어내에 해당 문자열 존재하는 경우 
            int j = 0;
            for(int i = startIndex; i<= lastIndex; i++){
                result[j] = str[i];
                j++;
            }
            result[j] = '\0';
            return 1;
        }
        else   { //다음 접미어로 이동
            accummulated_num_words += m_strlen(&str[Suffix[index]]) - LCP[index];
            index++;
        }
    }
    return 0;
}
/* 테스트 코드: food문자열의 부분 문자열을 사전순으로 정렬했을때 8번째 문자열 출력하시오. 이때 중복 문자열은 제외해야 함*/
int main(){
    generate_Suffix_array();
    generate_LCP_array();
    int res = get_kth_word(8);
    if(res)
        printf("%s\n", result);
    else
        printf("none\n");
    return 0;
}
```

 



* 11656 접미사

```c
#include<cstdio>

#define max 1000

int strcmp(char*a, char*b)
{
	int i = 0;

	while (1)
	{
		if (a[i]<b[i])return 1;
		else if (a[i]>b[i]) return 0;

		i++;

		if (a[i] == '\0')return 1;
		if (b[i] == '\0')return 0;

	}

}

void swap(char** x, char** y)
{
	char* temp = *x;
	*x = *y;
	*y = temp;
}

int choose_pivot(int low, int high)
{
	return low + (high - low) / 2;
}

int partition(char**a, int low, int high)
{
	int pivot_index = choose_pivot(low, high);
	char* pivot_value = a[pivot_index];
	int temp_index = low;

	swap(&a[high], &a[pivot_index]);

	for (int i = low; i < high; i++)
	{
		if (strcmp(a[i],pivot_value))
		{
			swap(&a[i], &a[temp_index]);
			temp_index += 1;
		}
	
	}

	swap(&a[temp_index], &a[high]);

	return temp_index;

}

void quicksort(char**a, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(a, low, high);

		quicksort(a, low, pivot - 1);
		quicksort(a, pivot + 1, high);
	}

}



int length(char*a)
{
	int i = 0;

	while (a[i] != '\0')i++;

	return i;

}

int main()
{
	char str[1001];
	char* suffix[1000];

	// 문자열 입력
	scanf("%s", str);
	

	// 문자열 길이 추출
	int L = length(str);

	// 접미사 주소 저장
	for (int i = 0; i < L; i++)suffix[i] = &str[i];

	
	quicksort(suffix, 0, L - 1);
	//swap(&suffix[0], &suffix[1]);





	for (int i = 0; i < L; i++)printf("%s\n", suffix[i]);

	//printf("%d", length(str));

	//printf("%s %s", str1, str2);

	//if (strcmp(suffix[0], suffix[1]) == 1)printf("%s %s", suffix[0], suffix[1]);
	//else printf("%s %s", suffix[1], suffix[0]);

	return 0;

}
```

