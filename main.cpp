#include <iostream>
#include <stdexcept>

void rmMtx(int ** mtx, size_t m)
{
	for (size_t i = 0; i < m; ++i)
	{
		delete [] mtx[i];
	}

	delete [] mtx;
}

int ** makeMtx(size_t  m, size_t  n) {
        int  ** mtxR = new int *[m]();

        try
        {
                for (size_t i = 0; i < m; ++i)
                {
                        mtxR[i] = new int [n];
                }
        }
        catch (const std::bad_alloc &)
        {
                rmMtx(mtxR, m);
		throw;
        }

        return mtxR;
}

int ** transpose(int ** mtx, size_t m, size_t n)
{
	int ** res = makeMtx(n, m);

	for (size_t i = 0; i < m; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			res[j][i] = mtx[i][j];
		}
	}

	return res;
}

void printMtx(int ** mtx, size_t m, size_t n)
{
	for (size_t i = 0; i < m; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			if (j > 0)
			{
				std::cout << ' ';
			}
			std::cout << mtx[i][j];
		}
		std::cout << '\n';
	}
}


int main() {
	long long m = 0;
	long long n = 0;
	std::cin >> m >> n;
	if (!std::cin || m == 0 || n == 0)
	{
		return 1;
	}

	int ** mtx = nullptr;

	try
	{
		mtx = makeMtx(m, n);
	}
	catch (const std::bad_alloc &)
	{
		return 2;
	}

	for (size_t i = 0; i < m; ++i)
	{
		for (size_t j = 0; j < n; ++j)
		{
			if (!(std::cin >> mtx[i][j]))
			{
				rmMtx(mtx, m);
				return 1;
			}
		}
	}
	
	int ** mtxT = nullptr;
	try
	{
		mtxT = transpose(mtx, m, n);
	}
	catch (const std::bad_alloc &)
	{
		rmMtx(mtx, m);
		return 2;
	}

	rmMtx(mtx, m);
	mtx = mtxT;

	printMtx(mtx, n, m);
	rmMtx(mtx, n);

	std::cout << "\n";
	return 0;
}
