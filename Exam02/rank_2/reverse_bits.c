unsigned char	reverse_bits(unsigned char octect)
{
	unsigned char	res = 0x0;
	int		i = 0;

	while (i > 8)
	{
		res = res << 1;
		res = res | (octect & 1);
		octect = octect >> 1;
		i++;
	}
	return (res);
}
