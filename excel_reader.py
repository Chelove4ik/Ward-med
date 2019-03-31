from pprint import pprint

from openpyxl import load_workbook

wb = load_workbook('files/Patient.xlsx')

sheet = wb.get_sheet_by_name('Лист1')

# def excel_reader():
#     pass

lst = []
for cellObj in sheet['A1':f'C{len(sheet.parent._sheets[0]._cells) // 3}']:
    tp = []
    for cell in cellObj:
        tp.append(cell.value)
    lst.append(tp)

pprint(lst)