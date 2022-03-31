#include "pch.h"
#include "..\mp2-lab5-polinom\list.h"

TEST(TList, CanCreateNewList)
{
	ASSERT_NO_THROW(TList<int> tl);
}

TEST(TList, NewCreatedListIsEmpty)
{
	TList<int> tl;
	ASSERT_TRUE(tl.IsEmpty());
}

TEST(TList, NotEmptyListIsNotEmpty)
{
	TList<int> tl;
	tl.InsFirst(10);

	ASSERT_TRUE(!tl.IsEmpty());
}

TEST(TList, CanInsertFirstElement)
{
	TList<int> tl;
	ASSERT_NO_THROW(tl.InsFirst(1));
}

TEST(TList, CanInsertLastElement)
{
	TList<int> tl;
	tl.InsFirst(1);
	ASSERT_NO_THROW(tl.InsLast(1));
}

TEST(TList, CanInsertCurrentElementWhenFirst)
{
	TList<int> tl;
	tl.InsFirst(1); tl.InsFirst(1);
	tl.InsFirst(1); tl.InsFirst(1);

	tl.Reset();
	ASSERT_NO_THROW(tl.InsCurrent(100));
}

TEST(TList, CanInsertCurrentElementWhenSecond)
{
	TList<int> tl;
	tl.InsFirst(1); tl.InsFirst(1);
	tl.InsFirst(1); tl.InsFirst(1);

	tl.Reset(); tl.GoNext();
	ASSERT_NO_THROW(tl.InsCurrent(100));
}

TEST(TList, CanInsertCurrentElementWhenPenultimate)
{
	TList<int> tl;
	tl.InsLast(1); tl.InsLast(1);
	tl.InsLast(1); tl.InsLast(1);

	tl.Reset();
	tl.GoNext(); tl.GoNext();
	tl.GoNext();

	ASSERT_NO_THROW(tl.InsCurrent(100));
}

TEST(TList, CanInsertCurrentElementWhenLast)
{
	TList<int> tl;
	tl.InsLast(1); tl.InsLast(1);
	tl.InsLast(1); tl.InsLast(1);

	tl.Reset();
	tl.GoNext(); tl.GoNext();
	tl.GoNext(); tl.GoNext();

	ASSERT_NO_THROW(tl.InsCurrent(100));
}

TEST(TList, CanDeleteFirstElement)
{
	TList<int> tl;
	tl.InsLast(1); tl.InsLast(1);
	tl.InsLast(1); tl.InsLast(1);

	ASSERT_NO_THROW(tl.DelFirst());
}

TEST(TList, CanDelete2CurrentElementsWhenFirst)
{
	TList<int> tl;
	tl.InsLast(1); tl.InsLast(1);
	tl.InsLast(1); tl.InsLast(1);

	tl.Reset();

	ASSERT_NO_THROW(tl.DelCurrent());
	ASSERT_NO_THROW(tl.DelCurrent());
}

TEST(TList, CanDeleteCurrentElementWhenSecond)
{
	TList<int> tl;
	tl.InsLast(1); tl.InsLast(1);
	tl.InsLast(1); tl.InsLast(1);

	tl.Reset();
	tl.GoNext();

	ASSERT_NO_THROW(tl.DelCurrent());

}

TEST(TList, CanDeleteCurrentElementWhenPenultimate)
{
	TList<int> tl;
	tl.InsLast(1); tl.InsLast(1);
	tl.InsLast(1); tl.InsLast(1);

	tl.Reset();
	tl.GoNext(); tl.GoNext();

	ASSERT_NO_THROW(tl.DelCurrent());
}

TEST(TList, CanDeleteCurrentElementWhenLast)
{
	TList<int> tl;
	tl.InsLast(1); tl.InsLast(1);
	tl.InsLast(1); tl.InsLast(1);

	tl.Reset();
	tl.GoNext(); tl.GoNext();
	tl.GoNext();

	ASSERT_NO_THROW(tl.DelCurrent());
}
