#include <iostream>
#include <fstream>

int st[100], n, i, k, p;
char porturi[21][21];
std::ofstream f("porturi.txt");

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
   	return 1;
}

int solutie()
{
   	return k == p;
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
    f << "porturi: \n{\n";
	for(i = 1; i <= k; i++)
	   	f << porturi[st[i]] << "\n";
    f << "}\n";
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

void citire()
{
    std::cin >> n;
    std::cin >> p;
    for(i = 1; i <= n; i++)
    {
        std::cin.get();
        std::cin.get(porturi[i], 20);
    }
}

int main()
{
   	citire();
   	back();
   	return 0;
}
