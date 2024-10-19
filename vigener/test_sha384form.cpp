#include <QtTest/QtTest>
#include "sha384form.h"

class TestSHA384Form : public QObject {
    Q_OBJECT

private slots:
    void testHashText();
};

void TestSHA384Form::testHashText() {
    SHA384Form form;

    QString text = "hello";
    QString expectedHash = "59e1748777448c69de6b800d7a33bbfb9e8bc3b8c6f0f50a3e343dca220e82abf07f424d8fdb4166e98f0d8b902d6fb8663a1bc9a27a6db8a7e3a107e589a1d8";
    QString resultHash = form.hashText(text);

    QCOMPARE(resultHash, expectedHash);
}

QTEST_MAIN(TestSHA384Form)
#include "test_sha384form.moc"
