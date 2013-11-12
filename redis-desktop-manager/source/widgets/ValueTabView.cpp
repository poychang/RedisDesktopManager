#include "ValueTabView.h"


void ValueTabView::init(QWidget * baseController, ValueTabView::Type t)
{
	controller = baseController;
	viewType = t;

	initLayout();

	initKeyName();

	initKeyValue();
}

void ValueTabView::initLayout()
{
	controller->resize(513, 313);
	gridLayout = new QGridLayout(controller);
	gridLayout->setSpacing(6);
	gridLayout->setContentsMargins(11, 11, 11, 11);
	gridLayout->setObjectName(QStringLiteral("gridLayout"));
}

void ValueTabView::initKeyName()
{
	keyName = new QLineEdit(controller);
	keyName->setObjectName(QStringLiteral("keyName"));
	keyName->setEnabled(true);
	keyName->setReadOnly(true);

	gridLayout->addWidget(keyName, 0, 1, 1, 1);

	keyNameLabel = new QLabel(controller);
	keyNameLabel->setText("Key:");

	gridLayout->addWidget(keyNameLabel, 0, 0, 1, 1);
}

void ValueTabView::initKeyValue()
{
	if (viewType == ModelBased) {

		keyValue = new QTableView(controller);
		keyValue->setEditTriggers(QAbstractItemView::NoEditTriggers);
		keyValue->setWordWrap(true);
		keyValue->horizontalHeader()->setDefaultSectionSize(220);
		gridLayout->addWidget(keyValue, 1, 1, 1, 1);

	} else {

		keyValuePlain = new QPlainTextEdit(controller);
		keyValuePlain->setReadOnly(true);
		gridLayout->addWidget(keyValuePlain, 1, 1, 1, 1);
	}

	keyValueLabel = new QLabel(controller);
	keyValueLabel->setText("Value:");
	gridLayout->addWidget(keyValueLabel, 1, 0, 1, 1);
}

void ValueTabView::setModel(QAbstractItemModel * model)
{
	if (keyValue == nullptr) {
		return;
	}

	keyValue->setModel(model);
	keyValue->setVisible(false);
	keyValue->resizeRowsToContents();
	keyValue->setVisible(true);
}

void ValueTabView::setPlainValue(QString &value)
{
	if (keyValuePlain == nullptr) {
		return;
	}

	keyValuePlain->setPlainText(value);
}

ValueTabView::Type ValueTabView::getType()
{
	return viewType;
}