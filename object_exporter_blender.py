import bpy
import bmesh

file = open("D:/Users/marvi/Desktop/object.txt", "w")

for obj in bpy.data.objects:
    if (obj.type == 'MESH'):
        file.write("mesh name=" + obj.name + "\n")
        bm = bmesh.new()
        bm.from_mesh(obj.data)
        bmesh.ops.triangulate(bm, faces=bm.faces[:], quad_method='BEAUTY', ngon_method='BEAUTY')
        uv_lay = bm.loops.layers.uv.active
        index = int
        index = 0
        indextracker = []
        for f in bm.faces:
            for l in f.loops:
                tuple = (l.vert.co.x, l.vert.co.y, l.vert.co.z, 
                         l.vert.normal.x, l.vert.normal.y, l.vert.normal.z, 
                         l[uv_lay].uv[0], l[uv_lay].uv[1])
                if tuple in indextracker:
                    file.write("i" + str(indextracker.index(tuple)) + "\n")
                else:
                    file.write(str(index) + "\n")
                    mat = obj.matrix_world.copy()
                    vt = l.vert.co.copy()
                    nm = l.vert.normal.copy()
                    vt = mat @ vt
                    nm = mat @ nm
                    file.write(str(vt.x) + "\n")
                    file.write(str(vt.y) + "\n")
                    file.write(str(vt.z) + "\n")
                    file.write(str(nm.x) + "\n")
                    file.write(str(nm.y) + "\n")
                    file.write(str(nm.z) + "\n")
                    file.write(str(l[uv_lay].uv[0]) + "\n")
                    file.write(str(l[uv_lay].uv[1]) + "\n")
                
                    indextracker.append(tuple)
                                     
                    index = index + 1
                    
file.write("skeleton\n")

armature_ob = bpy.data.objects["Armature"]

file.write("armature mat\n")
for i in range(4):
    for j in range(4):
        file.write(str(armature_ob.matrix_world[j][i]) + "\n")
                
for bone in bpy.data.objects['Armature'].pose.bones:
    if (len(bone.parent_recursive) > 0):
        file.write("p " + bone.name + "\n")
        file.write(bone.parent_recursive[0].name + "\n")
    else:
        file.write(bone.name + "\n")
        
    for i in range(4):
        for j in range(4):
            file.write(str(bone.matrix[j][i]) + "\n")
            
file.write("parentbones\n")
        
for obj in bpy.data.objects:
    if (obj.parent_bone != ""):
        file.write(obj.name + "\n")
        file.write(obj.parent_bone + "\n")
    
        
        
file.close()
    
