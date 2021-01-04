#include <iostream>

int st[100], n, i, k, p;

void init()
{
    st[k] = -1;
}

int succesor()
{
   	if(st[k] < 1)
   	{
		st[k]++;
		return 1;
   	}
   	else
		return 0;
}

int valid()
{
   	return 1;
}

int solutie()
{
   	return k == n;
}

int solutie_comb()
{
	int t = 0;
    for (i = 1; i <= k; i++)
    {
        if(st[i] == 1)
            t++;
    }
	return t == p;
}

void afisare()
{
	for(i = 1; i <= k; i++)
		if(st[i] == 1)
	   		std::cout << i << " ";
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
	    	{
				if(solutie_comb())
					afisare();
	    	}
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

int main()
{
   	std::cin >> n;
    std::cin >> p;
   	back();
   	return 0;
}