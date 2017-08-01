#include "FILTER.H"
u16 filter(u16 *ary,u8 num,u16 MaxValue,u16 MinValue)
{
	int angleDataloopTemp2;
	u16 finalData=0;
	int maxValue = MinValue;
	int minValue = MaxValue;
	for (angleDataloopTemp2 = 0; angleDataloopTemp2 < num; angleDataloopTemp2++) //�ҳ����ֵ����Сֵ
	{
		if (ary[angleDataloopTemp2] > maxValue) //ȥ�����ֵ��Сֵ
		{
			maxValue = ary[angleDataloopTemp2];
		}
		if (ary[angleDataloopTemp2] < minValue) //ȥ�����ֵ��Сֵ
		{
			minValue = ary[angleDataloopTemp2];
		}
		finalData += ary[angleDataloopTemp2];
	}
	finalData -= (maxValue + minValue);  //ȥ�����ֵ��Сֵ
	finalData /= (num-2);	 //ȡƽ��ֵ
	return finalData;
}
double KalmanFilter(const double ResrcData,
double ProcessNiose_Q, double MeasureNoise_R, double InitialPrediction)
{
	double R = MeasureNoise_R;
	double Q = ProcessNiose_Q;

	static        double x_last;

	double x_mid = x_last;
	double x_now;

	static        double p_last;

	double p_mid;
	double p_now;
	double kg;

	x_mid = x_last; //x_last=x(k-1|k-1),x_mid=x(k|k-1)
	p_mid = p_last + Q; //p_mid=p(k|k-1),p_last=p(k-1|k-1),Q=����
	kg = p_mid / (p_mid + R); //kgΪkalman filter��RΪ����
	x_now = x_mid + kg*(ResrcData - x_mid);//���Ƴ�������ֵ

	p_now = (1 - kg)*p_mid;//����ֵ��Ӧ��covariance       

	p_last = p_now; //����covarianceֵ
	x_last = x_now; //����ϵͳ״ֵ̬

	return x_now;
}

