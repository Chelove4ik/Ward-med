from openpyxl import load_workbook

wb = load_workbook('files/Patient.xlsx')

sheet = wb.get_sheet_by_name('Лист1')

list_patients = []
for cellObj in sheet['A1':f'D{len(sheet.parent._sheets[0]._cells) // 4}']:
    tp = []
    for cell in cellObj:
        tp.append(str(cell.value))
    list_patients.append(tp)
