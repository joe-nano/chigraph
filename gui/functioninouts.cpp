#include "functioninouts.hpp"
#include "functionview.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QVBoxLayout>

#include <KLocalizedString>

FunctionInOuts::FunctionInOuts(QWidget* parent) : QWidget(parent) {
	setSizePolicy({QSizePolicy::Preferred, QSizePolicy::Preferred});

	auto layout = new QVBoxLayout;
	setLayout(layout);

	layout->addWidget(new QLabel(i18n("Exec Inputs")));
	execins = new ExecParamListWidget;
	layout->addWidget(execins);

	layout->addWidget(new QLabel(i18n("Exec Outputs")));
	execouts = new ExecParamListWidget();
	layout->addWidget(execouts);

	layout->addWidget(new QLabel(i18n("Data Inputs")));
	ins = new ParamListWidget;
	layout->addWidget(ins);

	layout->addWidget(new QLabel(i18n("Data Outputs")));
	outs = new ParamListWidget;
	layout->addWidget(outs);
}

void FunctionInOuts::loadFunction(FunctionView* func) {
	mFuncView = func;
	mFunc     = func->function();

	execins->setFunction(func, ExecParamListWidget::Input);
	execouts->setFunction(func, ExecParamListWidget::Output);

	ins->setFunction(func, ParamListWidget::Input);
	outs->setFunction(func, ParamListWidget::Output);
}