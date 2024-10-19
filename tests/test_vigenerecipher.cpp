#include <QtTest/QtTest>
#include "vigenerecipher.h"

class TestVigenereCipherForm : public QObject {
    Q_OBJECT

private slots:
    void testEncrypt();
    void testDecrypt();
};

void TestVigenereCipherForm::testEncrypt() {
    VigenereCipherForm form;

    QString text = "HELLO";
    QString key = "KEY";
    QString expectedEncrypted = "RIJVS";
    QString result = form.encrypt(text, key);

    QCOMPARE(result, expectedEncrypted);
}

void TestVigenereCipherForm::testDecrypt() {
    VigenereCipherForm form;

    QString encryptedText = "RIJVS";
    QString key = "KEY";
    QString expectedDecrypted = "HELLO";
    QString result = form.decrypt(encryptedText, key);

    QCOMPARE(result, expectedDecrypted);
}

QTEST_MAIN(TestVigenereCipherForm)
#include "test_vigenerecipher.moc"
