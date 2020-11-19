import bpy
import bmesh

file = open("D:/Users/marvi/Desktop/anim.txt", "w")

armature_ob = bpy.data.objects["Armature"]

sce = bpy.context.scene

keyframes = []

action = bpy.data.actions["ArmatureAction.001"]
for fcu in action.fcurves:
    for keyframe in fcu.keyframe_points:
        keyframes.append(int(keyframe.co[0]))

#remove duplicates
keyframes = list(dict.fromkeys(keyframes))

sce = bpy.context.scene

for frame in keyframes:
    sce.frame_set(frame)
    bpy.context.view_layer.update()
    file.write("f" + str(frame) + "\n")
    for bone in bpy.data.objects['Armature'].pose.bones:
        file.write("b " + bone.name + "\n")
        mat = bone.matrix_basis
        for i in range(4):
            for j in range(4):
                file.write(str(mat[j][i]) + "\n")

file.close()
