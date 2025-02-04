#include "T_About.h"

#include <QHBoxLayout>
#include <QIcon>
#include <QVBoxLayout>

#include "ElaImageCard.h"
#include "ElaText.h"
T_About::T_About(QWidget* parent)
    : ElaWidget(parent)
{
    setWindowTitle("About...");
    setWindowIcon(QIcon(":/include/Image/Moon.jpg"));
    this->setIsFixedSize(true);
    setWindowModality(Qt::ApplicationModal);
    setWindowButtonFlags(ElaAppBarType::CloseButtonHint);
    ElaImageCard* pixCard = new ElaImageCard(this);
    pixCard->setFixedSize(60, 60);
    pixCard->setIsPreserveAspectCrop(false);
    pixCard->setCardImage(QImage(":/include/Image/Moon.jpg"));

    QVBoxLayout* pixCardLayout = new QVBoxLayout();
    pixCardLayout->addWidget(pixCard);
    pixCardLayout->addStretch();

    ElaText* versionText = new ElaText("ElaWidgetTools-LK-2025", this);
    QFont versionTextFont = versionText->font();
    versionTextFont.setWeight(QFont::Bold);
    versionText->setFont(versionTextFont);
    versionText->setWordWrap(false);
    versionText->setTextPixelSize(18);

    ElaText* licenseText = new ElaText("MIT License", this);
    licenseText->setWordWrap(false);
    licenseText->setTextPixelSize(14);
    ElaText* supportText = new ElaText("Windows: QT5.12 and above\nLinux: Qt5.14 and above", this);
    supportText->setWordWrap(false);
    supportText->setTextPixelSize(14);
    ElaText* contactText = new ElaText("Author: 8009963@qq.com\nGroup: 850243692(QQ)", this);
    contactText->setWordWrap(false);
    contactText->setTextInteractionFlags(Qt::TextSelectableByMouse);
    contactText->setTextPixelSize(14);
    ElaText* helperText = new ElaText("User Manual and API Documents are available for a fee.\nProvide additional technique support.", this);
    helperText->setWordWrap(false);
    helperText->setTextPixelSize(14);
    ElaText* copyrightText = new ElaText("Copyright© 2024 Liniyous", this);
    copyrightText->setWordWrap(false);
    copyrightText->setTextPixelSize(14);

    QVBoxLayout* textLayout = new QVBoxLayout();
    textLayout->setSpacing(15);
    textLayout->addWidget(versionText);
    textLayout->addWidget(licenseText);
    textLayout->addWidget(supportText);
    textLayout->addWidget(contactText);
    textLayout->addWidget(helperText);
    textLayout->addWidget(copyrightText);
    textLayout->addStretch();

    QHBoxLayout* contentLayout = new QHBoxLayout();
    contentLayout->addSpacing(30);
    contentLayout->addLayout(pixCardLayout);
    contentLayout->addSpacing(30);
    contentLayout->addLayout(textLayout);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 25, 0, 0);
    mainLayout->addLayout(contentLayout);
}

T_About::~T_About()
{
}
