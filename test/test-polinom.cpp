#include "pch.h"
#include "..\mp2-lab5-polinom\polinom.h"


TEST(TPolinom, CanCreateNewPolinom)
{
	ASSERT_NO_THROW(TPolinom tp);
}


TEST(TPolinom, CanCreateCopiedPolinom)
{
	TPolinom tp;
	ASSERT_NO_THROW(TPolinom tp2(tp));
}

TEST(TPolinom, CanAssignPolinoms)
{
	TPolinom tp1;
	TMonom tm(2, 0, 0, 0);
	tp1.AddMonom(tm);

	TPolinom tp2;

	ASSERT_NO_THROW(tp2 = tp1);
}

TEST(TPolinom, CanAssignPolinomToItself)
{
	TPolinom tp;
	TMonom tm(2, 0, 0, 0);
	tp.AddMonom(tm);

	ASSERT_NO_THROW(tp = tp);
}

TEST(TPolinom, CanAddMonomToPolinom)
{
	TPolinom tp;
	TMonom tm(2, 0, 0, 0);
	ASSERT_NO_THROW(tp.AddMonom(tm));
}

TEST(TPolinom, CanAddPolinomToPolinom_1)
{
	TPolinom tp1;
	TMonom tm1(1, 1, 0, 0);
	TMonom tm2(1, 0, 0, 0);
	tp1.AddMonom(tm1);
	tp1.AddMonom(tm2);

	TPolinom tp2;
	TMonom tm3(-1, 1, 0, 0);
	TMonom tm4(-1, 0, 0, 0);
	tp2.AddMonom(tm3);
	tp2.AddMonom(tm4);

	TPolinom sum;
	ASSERT_NO_THROW(sum = tp1 + tp2);

	TPolinom correct;

	EXPECT_TRUE(sum == correct);
	//EXPECT_EQ(sum, correct);
}

TEST(TPolinom, CanAddPolinomToPolinom_2)
{
	TPolinom tp1;
	TMonom tm1(1, 1, 0, 0);
	TMonom tm2(1, 0, 0, 0);
	tp1.AddMonom(tm1);
	tp1.AddMonom(tm2);

	TPolinom tp2;
	TMonom tm3(-1, 1, 0, 0);
	tp2.AddMonom(tm3);

	TPolinom sum;
	ASSERT_NO_THROW(sum = tp1 + tp2);

	TPolinom correct;
	TMonom tm4(1, 0, 0, 0);
	correct.AddMonom(tm4);

	EXPECT_TRUE(sum == correct);
	//EXPECT_EQ(sum, correct);
}

TEST(TPolinom, CanAddPolinomToPolinom_3)
{
	TPolinom tp1;
	TMonom tm1(1, 1, 0, 0);
	TMonom tm2(1, 0, 0, 0);
	tp1.AddMonom(tm1);
	tp1.AddMonom(tm2);

	TPolinom tp2;
	TMonom tm3(-1, 0, 0, 0);
	tp2.AddMonom(tm3);

	
	TPolinom sum;
	ASSERT_NO_THROW(sum = tp1 + tp2);
	
	TPolinom correct;
	TMonom tm4(1, 1, 0, 0);
	correct.AddMonom(tm4);

	EXPECT_TRUE(sum == correct);
	//EXPECT_EQ(sum, correct);
}


TEST(TPolinom, CanMultiplyPolinomByZeroDouble)
{
	TPolinom tp;
	TMonom tm1(1, 0, 1, 1);
	TMonom tm2(2, 1, 0, 1);
	TMonom tm3(3, 1, 1, 1);
	tp.AddMonom(tm1);
	tp.AddMonom(tm2);
	tp.AddMonom(tm3);

	TPolinom res;
	ASSERT_NO_THROW(res = 0 * tp);

	EXPECT_TRUE(res == TPolinom());
	//EXPECT_EQ(res, TPolinom());
}

TEST(TPolinom, CanMultiplyPolynomByDouble)
{
	TPolinom tp;
	TMonom tm1(1, 0, 1, 1);
	TMonom tm2(2, 1, 0, 1);
	TMonom tm3(3, 1, 1, 1);
	tp.AddMonom(tm1);
	tp.AddMonom(tm2);
	tp.AddMonom(tm3);

	TPolinom res;
	ASSERT_NO_THROW(res = -10 * tp);

	TPolinom correct;
	TMonom tm4(-10, 0, 1, 1);
	TMonom tm5(-20, 1, 0, 1);
	TMonom tm6(-30, 1, 1, 1);
	correct.AddMonom(tm4);
	correct.AddMonom(tm5);
	correct.AddMonom(tm6);

	EXPECT_TRUE(res == correct);
	//EXPECT_EQ(res, correct);
}

TEST(TPolinom, CanMultiplyPolinomByMonom)
{
	TPolinom tp;
	TMonom tm1(1, 0, 1, 0);
	TMonom tm2(1, 1, 0, 0);
	tp.AddMonom(tm1);
	tp.AddMonom(tm2);

	TMonom tm3(2, 1, 0, 1);

	TPolinom res;
	ASSERT_NO_THROW(res = tp * tm3);

	TPolinom correct;
	TMonom tm4(2, 2, 0, 1);
	TMonom tm5(2, 1, 1, 1);
	correct.AddMonom(tm4);
	correct.AddMonom(tm5);

	EXPECT_TRUE(res == correct);
	//EXPECT_EQ(res, correct);
}

TEST(TPolinom, CanMultiplyPolinomByPolynom)
{
	TPolinom tp1;
	TMonom tm1(1, 1, 0, 0);
	tp1.AddMonom(tm1);

	TPolinom tp2;
	TMonom tm2(2, 0, 1, 1);
	TMonom tm3(0.5, 0, 0, 1);
	tp2.AddMonom(tm2);
	tp2.AddMonom(tm3);

	TPolinom res;
	ASSERT_NO_THROW(res = tp1 * tp2);

	TPolinom correct;
	TMonom tm4(2, 1, 1, 1);
	TMonom tm5(0.5, 1, 0, 1);
	correct.AddMonom(tm4);
	correct.AddMonom(tm5);

	EXPECT_TRUE(res == correct);
	//EXPECT_EQ(res, correct);
}
