#include "pch.h"
#include "CppUnitTest.h"
#include "../../DoubleLinkedList/DoublyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DoublyLinkedListTests
{
    TEST_CLASS(IteratorTests)
    {
    public:
        TEST_METHOD(LeftShiftOperator_EmptyIntCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const DoublyLinkedList<int> emptyList;
            std::stringstream buffer;
            const std::string expected = " ";

            //Act
            buffer << emptyList;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_EmptyStringCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const DoublyLinkedList<std::string> emptyList;
            std::stringstream buffer;
            const std::string expected = " ";

            //Act
            buffer << emptyList;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_OneIntElementCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const DoublyLinkedList<int> list = { 1 };
            std::stringstream buffer;
            const std::string expected = "1";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_OneStringElementCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const DoublyLinkedList<std::string> list = { "1" };
            std::stringstream buffer;
            const std::string expected = "1";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_IntCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const DoublyLinkedList<int> list = { 1, 2, 3 };
            std::stringstream buffer;
            const std::string expected = "1 2 3";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(LeftShiftOperator_StringCollection_SpaceBetweenCurveBraces)
        {
            //Arrange
            const DoublyLinkedList<std::string> list = { "1", "2", "3" };
            std::stringstream buffer;
            const std::string expected = "1 2 3";

            //Act
            buffer << list;

            //Assert
            Assert::AreEqual(expected, buffer.str());
        }

        TEST_METHOD(GetFirst_IntCollection_AreEqualFirstItem)
        {
            //Arrange
            DoublyLinkedList<int> list = { 1, 2, 3 };
            const auto expected = 1;

            //Act
            const auto actual = *list.cbegin();

            //Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(GetFirst_StringCollection_AreEqualFirstItem)
        {
            //Arrange
            DoublyLinkedList<std::wstring> list = { L"1", L"2", L"3" };
            const std::wstring expected = L"1";

            //Act
            const auto& actual = *list.cbegin();

            //Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(Add_IntCollection_AreEqualAddBack)
        {
            //Arrange
            DoublyLinkedList<int> list = { 1, 2, 3 };

            const DoublyLinkedList<int> expected = { 1, 2, 3, 4 };

            //Act
            list.addEnd(4);

            //Assert
            Assert::AreEqual(expected, list);
        }

        TEST_METHOD(Add_IntEmptyCollection_OneIntElementInCollection)
        {
            //Arrange
            DoublyLinkedList<int> empty = {};

            const DoublyLinkedList<int> expected = { 1 };

            //Act
            empty.addEnd(1);

            //Assert
            Assert::AreEqual(expected, empty);
        }

        TEST_METHOD(Add_StringCollection_AreEqualAddBack)
        {
            // TODO: так как у теста только wostream и есть проблема со string,
            // то нужно использовать wstring вместо string

            //Arrange
            DoublyLinkedList<std::wstring> list = { L"1", L"2", L"3" };

            const DoublyLinkedList<std::wstring> expected = { L"1", L"2", L"3", L"4" };

            //Act
            list.addEnd(L"4");

            //Assert
            Assert::AreEqual(expected, list);
        }

        TEST_METHOD(AreEqualOperator_SameIntColletion_Success)
        {
            //Arrange
            const DoublyLinkedList<int> list = { 1, 2, 3 };
            //Act
            //Assert
            Assert::AreEqual(list, list);
        }

        TEST_METHOD(AreEqualOperator_TwoIntColletions_Success)
        {
            //Arrange
            const DoublyLinkedList<int> expected = { 1, 2, 3 };
            const DoublyLinkedList<int> actual = { 1, 2, 3 };
            //Act
            //Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(AreNotEqual_IntCollectionAndEmptyCollection_NotSuccess)
        {
            //Arrange
            const DoublyLinkedList<int> list = { 1, 2, 3 };
            const DoublyLinkedList<int> emptyList;

            Assert::AreNotEqual(list, emptyList);
        }

        TEST_METHOD(AreNotEqual_IntCollectionsDifferentLengthLeftLonger_NotSuccess)
        {
            //Arrange
            const DoublyLinkedList<int> expected = { 1, 2, 3 };
            const DoublyLinkedList<int> actual = { 1, 2 };

            Assert::AreNotEqual(expected, actual);
        }
        TEST_METHOD(AreNotEqual_IntCollectionsDifferentLengthLeftShorter_NotSuccess)
        {
            //Arrange
            const DoublyLinkedList<int> expected = { 1, 2, 3 };
            const DoublyLinkedList<int> actual = { 1, 2, 3, 4 };

            Assert::AreNotEqual(expected, actual);
        }

        TEST_METHOD(AreEqualOperator_SameStringColletions_Success)
        {
            //Arrange
            const DoublyLinkedList<std::wstring> list = { L"1", L"2", L"3" };

            //Act & Assert
            Assert::AreEqual(list, list);
        }

        TEST_METHOD(AreEqualOperator_TwoStringColletions_Success)
        {
            //Arrange
            const DoublyLinkedList<std::wstring> expected = { L"1", L"2", L"3" };
            const DoublyLinkedList<std::wstring> actual = { L"1", L"2", L"3" };

            //Act & Assert
            Assert::AreEqual(expected, actual);
        }

        TEST_METHOD(AreNotEqual_StringtCollectionAndEmptyCollection_NotSuccess)
        {
            //Arrange
            const DoublyLinkedList<std::wstring> list = { L"1", L"2", L"3" };
            const DoublyLinkedList<std::wstring> emptyList;

            //Act & Assert
            Assert::AreNotEqual(list, emptyList);
        }

        TEST_METHOD(AreNotEqual_StringCollectionsDifferentLengthLeftLonger_NotSuccess)
        {
            //Arrange
            const DoublyLinkedList<std::wstring> expected = { L"1", L"2", L"3" };
            const DoublyLinkedList<std::wstring> actual = { L"1", L"2" };


            Assert::AreNotEqual(expected, actual);
        }

        TEST_METHOD(AreNotEqual_StringCollectionsDifferentLengthLeftShorter_NotSuccess)
        {
            //Arrange
            const DoublyLinkedList<std::wstring> expected = { L"1", L"2", L"3" };
            const DoublyLinkedList<std::wstring> actual = { L"1", L"2", L"3", L"4" };

            Assert::AreNotEqual(expected, actual);
        }
    };
}