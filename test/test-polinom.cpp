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
}

TEST(TPolinom, CanAddPolinomToPolinom_4)
{
	TPolinom tp1;
	TMonom tm1(1, 1, 2, 3);
	TMonom tm2(7, 5, 5, 4);
	TMonom tm3(10, 2, 7, 8);
	tp1.AddMonom(tm1);
	tp1.AddMonom(tm2);
	tp1.AddMonom(tm3);

	TPolinom tp2;
	TMonom tm4(-1, 1, 2, 3);
	TMonom tm5(-5, 5, 5, 4);
	tp2.AddMonom(tm4);
	tp2.AddMonom(tm5);


	TPolinom sum;
	ASSERT_NO_THROW(sum = tp1 + tp2);

	TPolinom correct;
	TMonom tm6(10, 2, 7, 8);
	TMonom tm7(2, 5, 5, 4);
	correct.AddMonom(tm6);
	correct.AddMonom(tm7);

	EXPECT_TRUE(sum == correct);
}

TEST(TPolinom, CanAddPolinomToPolinom_5)
{
	TPolinom tp1;
	TMonom tm1(10, 2, 2, 3);
	TMonom tm2(7, 5, 5, 4);
	TMonom tm3(10, 2, 7, 8);
	tp1.AddMonom(tm1);
	tp1.AddMonom(tm2);
	tp1.AddMonom(tm3);

	TPolinom tp2;
	TMonom tm4(-10, 2, 2, 3);
	TMonom tm5(-7, 5, 5, 4);
	tp2.AddMonom(tm4);
	tp2.AddMonom(tm5);


	TPolinom sum;
	ASSERT_NO_THROW(sum = tp1 + tp2);

	TPolinom correct;
	TMonom tm6(10, 2, 7, 8);
	correct.AddMonom(tm6);

	EXPECT_TRUE(sum == correct);
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
}

TEST(TPolinom, CanMultiplyPolinomByPolynom_1)
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
}

TEST(TPolinom, CanMultiplyPolinomByPolynom_2)
{
	TPolinom tp1;
	TMonom tm1(7, 2, 5, 8);
	TMonom tm2(4, 3, 5, 9);
	TMonom tm3(-2, 2, 2, 1);
	tp1.AddMonom(tm1);
	tp1.AddMonom(tm2);
	tp1.AddMonom(tm3);

	TPolinom tp2;
	TMonom tm4(2, 1, 1, 1);
	TMonom tm5(3, 1, 2, 3);
	TMonom tm6(8, 5, 7, 2);
	tp2.AddMonom(tm4);
	tp2.AddMonom(tm5);
	tp2.AddMonom(tm6);

	TPolinom res;
	ASSERT_NO_THROW(res = tp1 * tp2);

	TPolinom correct;
	TMonom tm7(32, 8, 12, 11);
	TMonom tm8(56, 7, 12, 10);
	TMonom tm9(-16, 7, 9, 3);
	TMonom tm10(12, 4, 7, 12);
	TMonom tm11(8, 4, 6, 10);
	TMonom tm12(21, 3, 7, 11);
	TMonom tm13(14, 3, 6, 9);
	TMonom tm14(-6, 3, 4, 4);
	TMonom tm15(-4, 3, 3, 2);
	correct.AddMonom(tm7);
	correct.AddMonom(tm8);
	correct.AddMonom(tm9);
	correct.AddMonom(tm10);
	correct.AddMonom(tm11);
	correct.AddMonom(tm12);
	correct.AddMonom(tm13);
	correct.AddMonom(tm14);
	correct.AddMonom(tm15);

	EXPECT_TRUE(res == correct);
}
