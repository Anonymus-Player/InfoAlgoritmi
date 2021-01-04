#include <iostream>

int st[100], stint[100], n, i, k, p;

void init()
{
    st[k] = 0;
}

int succesor()
{
   	if(st[k] < n)
   	{
		st[k]++;
		return 1;
   	}
   	else
		return 0;
}

int valid()
{
    for(i = 1; i <= k - 1; i++)
        if(st[k] == st[i])
            return 0;
    return 1;
}

int solutie()
{
   	return k == n;
}

void afisare()
{
	for(i = 1; i <= k; i++)
	   	std::cout << stint[st[i]] << " ";
    std::cout << "\n";
}

void back()
{
   	int as;
   	k = 1;
   	init();
	while(k > 0)
   	{
    	do{}while((as = succesor()) && !valid());
		if(as)
		{
	    	if(solutie())
				afisare();
	    	else
	    	{
				k++;
				init();
	    	}
		}
		else
		{
	   		k--;
		}
   }
}

void examene()
{
    for(i = 1; i <= p; i++)
        stint[i] = i;
    for(i; i <= n; i++)
        stint[i] = 0;
}

int main()
{
   	std::cin >> n;
    std::cin >> p;
    examene();
   	back();
   	return 0;
}
