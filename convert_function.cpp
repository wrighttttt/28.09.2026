

int ** convert(const int * t, size_t n, const size_t * lns, size_t rows)
{	
	int ** res = new int *[rows];
	size_t i = 0;
	try
	{
		size_t offset = 0;

		for (; i < rows; ++i)
		{
			res[i] = new int [lns[i]];

			for (size_t j = 0; j < lns[i]; ++j)
			{
				res[i][j] = t[offset + j];
			}

			offset ++ lns[i];
		}
	}
	catch (const std::bad_alloc &)
	{
		for (size_t k = 0; k < 1; ++k)
		{
			delete [] res[k];
		}

		delete [] res;
		throw;
	}

	return res;
}



